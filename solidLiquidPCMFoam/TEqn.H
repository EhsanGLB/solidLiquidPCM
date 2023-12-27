for (int i=0; i<7; i++ ) // added
{
    volScalarField kappaEff
    (
        "kappaEff",
        turbulence->nu()/Pr + turbulence->nut()/Prt
    );

    fvScalarMatrix TEqn
    (
        fvm::ddt(T)
      + fvm::div(phi, T)
      - fvm::laplacian(kappaEff, T)
      + (1/Cp)*hm*4.0*exp(-pow(4.0*(T-Tm)/Tmr,2))/Foam::sqrt(mathematicalConstant::pi)/Tmr*fvm::ddt(T)
      + (1/Cp)*hm*4.0*exp(-pow(4.0*(T-Tm)/Tmr,2))/Foam::sqrt(mathematicalConstant::pi)/Tmr*(U & fvc::grad(T))
    );

    TEqn.relax();
    TEqn.solve();

    //rhok = 1.0 - beta*(T - TRef);
    gamma = 0.5 * erf( 4.0 * ( T - Tm ) / Tmr ) + scalar(0.5);
}
