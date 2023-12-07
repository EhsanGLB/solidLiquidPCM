    singlePhaseTransportModel laminarTransport(U, phi);

    // PCM properties
    dimensionedScalar rho(laminarTransport.lookup("rho"));
    dimensionedScalar Cp(laminarTransport.lookup("Cp"));
    dimensionedScalar beta(laminarTransport.lookup("beta"));
    dimensionedScalar Pr(laminarTransport.lookup("Pr"));
    dimensionedScalar hm(laminarTransport.lookup("hm"));
    dimensionedScalar Tm(laminarTransport.lookup("Tm"));
    dimensionedScalar Tmr(laminarTransport.lookup("Tmr"));


    // flow parameters
    dimensionedScalar TRef(laminarTransport.lookup("TRef"));
    dimensionedScalar Prt(laminarTransport.lookup("Prt"));
    dimensionedScalar Cu(laminarTransport.lookup("Cu"));
    dimensionedScalar b(laminarTransport.lookup("b"));
