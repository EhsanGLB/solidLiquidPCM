    // Solve the momentum equation

    volScalarField Vgamma ("Vgamma", Cu * pow( ( 1 - gamma ) , 2 ) / ( pow( gamma , 3 ) + b));

    fvVectorMatrix UEqn
    (
        fvm::ddt(U)
      + fvm::div(phi, U)
      + turbulence->divDevReff()
      + (1/rho)*fvm::SuSp(Vgamma, U)
    );

    UEqn.relax();

    if (piso.momentumPredictor())
    {
        solve
        (
            UEqn
         ==
            fvc::reconstruct
            (
                (
                    fvc::interpolate(rhok)*(g & mesh.Sf())
                  - fvc::snGrad(p)*mesh.magSf()
                )
            )
        );
    }
