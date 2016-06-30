#include "PActive.h"

PActive::PActive()
{ 
    TaggerAllHits = new TH1D("TaggerAllHits", "Tagger - All Hits", 352, 0, 352);
    TaggerSingles = new TH1D("TaggerSingles", "Tagger - Single Hits", 352, 0, 352);
    TaggerDoubles = new TH1D("TaggerDoubles", "Tagger - Double Hits", 352, 0, 352);

    hIM = new GH1("hIM", "IM", 400, 0, 400);
    hMM	= new GH1("hMM", "MM", 400, 800, 1200);

    hTime = new TH1D("hTime", "Neutral Pion Time;t_{#gamma}-t_{#pi^{0}} (ns)", 1400, -700, 700);
    hTCut = new TH1D("hTCut", "Neutral Pion Time;t_{#gamma}-t_{#pi^{0}} (ns)", 1400, -700, 700);
    hEkThMa = new GH3("hEkThMa", "Neutral Pion Missing Mass;Ek_{miss} (MeV);#theta_{miss} (deg);m_{miss} (MeV)", 100, 0, 200, 36, 0, 180, 80, 800, 1200);
    hEkEHMa = new GH3("hEkEHMa", "Neutral Pion Missing Mass;Ek_{miss} (MeV);APPT ESum Hardware;m_{miss} (MeV)", 100, 0, 200, 25, 0, 25, 80, 800, 1200);
    hEkESMa = new GH3("hEkESMa", "Neutral Pion Missing Mass;Ek_{miss} (MeV);APPT ESum Software;m_{miss} (MeV)", 100, 0, 200, 25, 0, 25, 80, 800, 1200);
    hTiEHMa = new GH3("hTiEHMa", "Neutral Pion Missing Mass;t_{#gamma}-t_{#pi^{0}}-t_{AT} (ns);APPT ESum Hardware;m_{miss} (MeV)", 200, -1000, 1000, 25, 0, 25, 80, 800, 1200);
    hTiESMa = new GH3("hTiESMa", "Neutral Pion Missing Mass;t_{#gamma}-t_{#pi^{0}}-t_{AT} (ns);APPT ESum Software;m_{miss} (MeV)", 200, -1000, 1000, 25, 0, 25, 80, 800, 1200);

    hTime_OA = new TH1D("hTime_OA", "Neutral Pion Time;t_{#gamma}-t_{#pi^{0}} (ns)", 1400, -700, 700);
    hTCut_OA = new TH1D("hTCut_OA", "Neutral Pion Time;t_{#gamma}-t_{#pi^{0}} (ns)", 1400, -700, 700);
    hEkThMa_OA = new GH3("hEkThMa_OA", "Neutral Pion Missing Mass;Ek_{miss} (MeV);#theta_{miss} (deg);m_{miss} (MeV)", 100, 0, 200, 36, 0, 180, 80, 800, 1200);
    hEkEHMa_OA = new GH3("hEkEHMa_OA", "Neutral Pion Missing Mass;Ek_{miss} (MeV);APPT ESum Hardware;m_{miss} (MeV)", 100, 0, 200, 25, 0, 25, 80, 800, 1200);
    hEkESMa_OA = new GH3("hEkESMa_OA", "Neutral Pion Missing Mass;Ek_{miss} (MeV);APPT ESum Software;m_{miss} (MeV)", 100, 0, 200, 25, 0, 25, 80, 800, 1200);
    hTiEHMa_OA = new GH3("hTiEHMa_OA", "Neutral Pion Missing Mass;t_{#gamma}-t_{#pi^{0}}-t_{AT} (ns);APPT ESum Hardware;m_{miss} (MeV)", 200, -1000, 1000, 25, 0, 25, 80, 800, 1200);
    hTiESMa_OA = new GH3("hTiESMa_OA", "Neutral Pion Missing Mass;t_{#gamma}-t_{#pi^{0}}-t_{AT} (ns);APPT ESum Software;m_{miss} (MeV)", 200, -1000, 1000, 25, 0, 25, 80, 800, 1200);

    hTime_Ch = new TH1D("hTime_Ch", "Neutral Pion Time;t_{#gamma}-t_{#pi^{0}} (ns)", 1400, -700, 700);
    hTCut_Ch = new TH1D("hTCut_Ch", "Neutral Pion Time;t_{#gamma}-t_{#pi^{0}} (ns)", 1400, -700, 700);
    hEkThMa_Ch = new GH3("hEkThMa_Ch", "Neutral Pion Missing Mass;Ek_{miss} (MeV);#theta_{miss} (deg);m_{miss} (MeV)", 100, 0, 200, 36, 0, 180, 80, 800, 1200);
    hEkEHMa_Ch = new GH3("hEkEHMa_Ch", "Neutral Pion Missing Mass;Ek_{miss} (MeV);APPT ESum Hardware;m_{miss} (MeV)", 100, 0, 200, 25, 0, 25, 80, 800, 1200);
    hEkESMa_Ch = new GH3("hEkESMa_Ch", "Neutral Pion Missing Mass;Ek_{miss} (MeV);APPT ESum Software;m_{miss} (MeV)", 100, 0, 200, 25, 0, 25, 80, 800, 1200);
    hTiEHMa_Ch = new GH3("hTiEHMa_Ch", "Neutral Pion Missing Mass;t_{#gamma}-t_{#pi^{0}}-t_{AT} (ns);APPT ESum Hardware;m_{miss} (MeV)", 200, -1000, 1000, 25, 0, 25, 80, 800, 1200);
    hTiESMa_Ch = new GH3("hTiESMa_Ch", "Neutral Pion Missing Mass;t_{#gamma}-t_{#pi^{0}}-t_{AT} (ns);APPT ESum Software;m_{miss} (MeV)", 200, -1000, 1000, 25, 0, 25, 80, 800, 1200);

    hEkOAMa = new GH3("hEkOAMa", "Neutral Pion Missing Mass;Ek_{miss} (MeV);Opening Angle (deg);m_{miss} (MeV)", 100, 0, 200, 36, 0, 180, 80, 800, 1200);
    hEkOAMa_AT = new GH3("hEkOAMa_AT", "Neutral Pion Missing Mass;Ek_{miss} (MeV);Opening Angle (deg);m_{miss} (MeV)", 100, 0, 200, 36, 0, 180, 80, 800, 1200);

    hTimevsTSum = new TH2D("hTimevsTSum", "Neutral Pion Time;t_{#gamma}-t_{#pi^{0}} (ns);APPT Time (ns)", 1400, -700, 700, 200, -1000, 1000);
    hTimevsTSum_AT = new TH2D("hTimevsTSum_AT", "Neutral Pion Time;t_{#gamma}-t_{#pi^{0}} (ns);APPT Time (ns)", 1400, -700, 700, 200, -1000, 1000);

    hChThMa_Hel0 = new GH3("hChThMa_Hel0", "Neutral Pion Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss} (MeV)", 352, 0, 352, 36, 0, 180, 80, 800, 1200);
    hChThMa_Hel1 = new GH3("hChThMa_Hel1", "Neutral Pion Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss} (MeV)", 352, 0, 352, 36, 0, 180, 80, 800, 1200);
    hChThMa_HelS = new GH3("hChThMa_HelS", "Neutral Pion Missing Mass;Tagger Channel;#theta_{#pi^{0}} (deg);m_{miss} (MeV)", 352, 0, 352, 36, 0, 180, 80, 800, 1200);

    OACut = 180;

    verbosity = 0;
    excl_pi0 = false;
    excl_pro = false;

    for(Int_t i=0; i<16; i++)
    {
        APPT_ADC[i] = 0;
        APPT_TDC[i] = 0;

        APPT_ADC_Ped[i] = 600;
        APPT_ADC_Gain[i] = 0.01;
        APPT_TDC_Off[i] = -20000;
        APPT_TDC_Gain[i] = 0.1;
        APPT_Use[i] = false;

        if(i==15) continue;

        APPT_Time[i] = 0;
        APPT_Ener[i] = 0;
        hAPPT_Time[i] = new TH1D(Form("hAPPT_Time%d",i+1),Form("APPT %02d Time;Time (ns)",i+1),200,-1000,1000);
        hAPPT_Ener[i] = new TH1D(Form("hAPPT_Ener%d",i+1),Form("APPT %02d Energy;Energy (#Photons)",i+1),250,0,25);
        hAPPT_EvsT[i] = new TH2D(Form("hAPPT_EvsT%d",i+1),Form("APPT %02d Energy vs Time;Time (ns);Energy (#Photons)",i+1),200,-1000,1000,250,0,25);
    }

    APPT_Scale = 1.00;

    hAPPT_TSum = new TH1D("hAPPT_TSum","APPT Time;Time (ns)",200,-1000,1000);

    APPT_ESumH = 0;
    hAPPT_ESumH = new TH1D("hAPPT_ESumH","APPT Energy Sum;Energy (#Photons)",250,0,25);
    hAPPT_EHvsT = new TH2D("hAPPT_EHvsT","APPT Energy Sum vs Time;Time (ns);Energy (#Photons)",200,-1000,1000,250,0,25);

    APPT_ESumS = 0;
    hAPPT_ESumS = new TH1D("hAPPT_ESumS","APPT Energy Sum;Energy (#Photons)",250,0,25);
    hAPPT_ESvsT = new TH2D("hAPPT_ESvsT","APPT Energy Sum vs Time;Time (ns);Energy (#Photons)",200,-1000,1000,250,0,25);

    hAPPT_EHvsES = new TH2D("hAPPT_EHvsES","APPT Energy Sum;Energy (#Photons);Energy (#Photons)",26,0,26,26,0,26);
    hAPPT_EHvsES_NePi = new TH2D("hAPPT_EHvsES_NePi","APPT Energy Sum;Energy (#Photons);Energy (#Photons)",26,0,26,26,0,26);
}

PActive::~PActive()
{
}

Bool_t	PActive::Init()
{
	cout << "Initialising physics analysis..." << endl;
	cout << "--------------------------------------------------" << endl << endl;

	if(!InitBackgroundCuts()) return kFALSE;
    if(!InitTargetMass()) return kFALSE;
    if(!InitVerbosity()) return kFALSE;
    if(!InitExclusivity()) return kFALSE;
    if(!InitOpeningAngle()) return kFALSE;
    if(!InitActiveChannel()) return kFALSE;
    if(!InitActiveScale()) return kFALSE;

    if(!PPhysics::Init()) return kFALSE;

    gTheory = new TGraph2D("Pi0P_SN11_F.txt");

    TaggerAccScal = GetScalerHist("TaggerAccScal");
    if(!TaggerAccScal)
    {
        cout << "No tagger scaler histogram available" << endl;
        return kFALSE;
    }
    VupromAccScal = GetScalerHist("VupromAccScal");

    cout << "--------------------------------------------------" << endl;
	return kTRUE;
}

Bool_t	PActive::Start()
{
    if(!IsGoATFile())
    {
        cout << "ERROR: Input File is not a GoAT file." << endl;
        return kFALSE;
    }
    SetAsPhysicsFile();

    for(Int_t i=0; i<16; i++)
    {
        GetDetectorHits()->SetNewBranchAddress(Form("APPT_ADC%d",i+1),&APPT_ADC[i]);
        GetDetectorHits()->SetNewBranchAddress(Form("APPT_TDC%d",i+1),&APPT_TDC[i]);
    }

    TraverseValidEvents();

    GoosyTagger(TaggerAccScal);
    if(VupromAccScal) GoosyTagger(VupromAccScal);

    return kTRUE;
}

void	PActive::ProcessEvent()
{
    // Reject if event had an error, otherwise grab the helicity
    if (!(IsMCFile()) && ((GetTrigger()->GetNErrors() > 0) || !(GetTrigger()->HasHelicity()))) return;
    Bool_t hel = GetTrigger()->GetHelicity();

    // Initial things for just the active target signals

    APPT_ESumS = 0;
    for(Int_t i=0; i<15; i++)
    {
        // Calibrate the ADC and TDC signals for each channel
        APPT_Ener[i] = APPT_ADC_Gain[i]*(APPT_ADC[i]-APPT_ADC_Ped[i]);
        APPT_Time[i] = APPT_TDC_Gain[i]*(APPT_TDC[i]-APPT_TDC_Off[i]);

        // If the energy is not below some threshold, fill some hists
        if(APPT_Ener[i]<0.5) continue;
        hAPPT_Ener[i]->Fill(APPT_Ener[i]);
        hAPPT_Time[i]->Fill(APPT_Time[i]);
        hAPPT_EvsT[i]->Fill(APPT_Time[i],APPT_Ener[i]);

        // Also add this energy to the software ESum
        if (APPT_Use[i]) APPT_ESumS += APPT_Ener[i];
    }

    // Calibrate the ADC and TDC signals for the analog sum signal
    APPT_ESumH = APPT_ADC_Gain[15]*(APPT_ADC[15]-APPT_ADC_Ped[15]);
    APPT_TSum = APPT_TDC_Gain[15]*(APPT_TDC[15]-APPT_TDC_Off[15]);
    hAPPT_TSum->Fill(APPT_TSum);
    hAPPT_ESumH->Fill(APPT_ESumH);
    hAPPT_EHvsT->Fill(APPT_TSum,APPT_ESumH);

    // If the final software ESum is non-zero, fill its histograms
    if(APPT_ESumS>0)
    {
        APPT_ESumS = APPT_ESumS*APPT_Scale;
        hAPPT_ESumS->Fill(APPT_ESumS);
        hAPPT_ESvsT->Fill(APPT_TSum,APPT_ESumS);
    }
    hAPPT_EHvsES->Fill(APPT_ESumS+0.5,APPT_ESumH+0.5);

    // Start looking for events with a pi0
    if (GetNeutralPions()->GetNParticles() == 1) hAPPT_EHvsES_NePi->Fill(APPT_ESumS+0.5,APPT_ESumH+0.5);

    if ((GetNeutralPions()->GetNParticles() != 1) && excl_pi0) return;
    if ((GetRootinos()->GetNParticles() != 1) && excl_pro) return;

    TLorentzVector beam, target, pi0, proton, missing;

    Int_t beam_channel;
    Double_t beam_time, beam_energy, beam_energy_cm, beam_pol, pi0_time, time, pi0_theta, pi0_theta_cm, pi0_phi, proton_theta, missing_theta, opening;
    target = GetTarget();

    // If specified in config, do double decoding, and then determine number of tagged photons
    if(GetDecodeDoubles()) GetTagger()->DecodeDoubles();
    Int_t nTagg = GetTagger()->GetNTagged();
    Int_t nDoub = GetTagger()->GetNDouble();

    if ((GetEventNumber()%100000 == 0) && (verbosity>0)) cout << endl << "Event " << GetEventNumber() << endl;

    // Loop over all tagger hits
    for (Int_t i = 0; i < (nTagg+nDoub); i++)
    {
        // Single tagger channel hits
        if (i < nTagg)
        {
            beam_channel = GetTagger()->GetTaggedChannel(i);
            beam_time = GetTagger()->GetTaggedTime(i);
            beam_energy = GetTagger()->GetTaggedEnergy(i);

            TaggerAllHits->Fill(beam_channel);
            if (RejectTagged(i)) continue;
            TaggerSingles->Fill(beam_channel);
            TaggerDoubles->Fill(beam_channel);

            if (verbosity>1) cout << endl << "Tagger Channel = " << beam_channel << "\tTagged Energy = " << beam_energy << endl << endl;
        }
        // Double tagger channel hits
        else
        {
            beam_channel = GetTagger()->GetDoubleRandom(i-nTagg);
            beam_time = GetTagger()->GetDoubleTime(i-nTagg);
            beam_energy = GetTagger()->GetDoubleEnergy(i-nTagg);

            if (RejectDouble(i-nTagg)) continue;
            TaggerDoubles->Fill(GetTagger()->GetDoubleRandom(i-nTagg));

            if (verbosity>1) cout << endl << "Double Channel = " << beam_channel << "\tTagged Energy = " << beam_energy << endl << endl;
        }

        beam = TLorentzVector(0., 0., beam_energy, beam_energy);
        beam_pol = CalcCircBeamPol(450.0, 0.8, beam_energy);

        // Loop over all neutral pions
        for (Int_t j = 0; j < GetNeutralPions()->GetNParticles(); j++)
        {
            // Determine pi0 kinematics, and fill related histograms
            pi0 = GetNeutralPions()->Particle(j);
            //pi0 = GetNeutralPions()->GetVector(j,134.98);
            pi0_time = GetNeutralPions()->GetTime(j);
            pi0_theta = GetNeutralPions()->GetTheta(j);
            pi0_phi = GetNeutralPions()->GetPhi(j);

            // CM conversion for theory calculation
            Double_t eout = 0, s = 0, t = 0, mp = 938.27;
            s = (TMath::Power(mp, 2)+(2*mp*beam_energy));
            beam_energy_cm = ((s-TMath::Power(mp, 2))/(2*TMath::Sqrt(s)));
            eout = (1/((1/ beam_energy)+(1-TMath::Cos(pi0_theta*TMath::DegToRad()))/mp));
            t = (-2*beam_energy*eout*(1-TMath::Cos(pi0_theta*TMath::DegToRad())));
            pi0_theta_cm = (TMath::ACos(1+t/(2*TMath::Power(beam_energy_cm, 2)))*TMath::RadToDeg());

            time = beam_time - pi0_time;
            hTime->Fill(time);
            hTimevsTSum->Fill(time,APPT_TSum);
            if((GHistBGSub::IsPrompt(time)) || (GHistBGSub::IsRandom(time))) hTCut->Fill(time);

            // Determine missing kinematics, and fill related histograms
            missing = beam + target - pi0;
            missing_theta = missing.Theta()*TMath::RadToDeg();
            hEkThMa->Fill(missing.E()-missing.M(),missing_theta,missing.M(),time);
            hEkEHMa->Fill(missing.E()-missing.M(),APPT_ESumH-0.5,missing.M(),time);
            hTiEHMa->Fill(time-APPT_TSum,APPT_ESumH-0.5,missing.M(),time);
            if(APPT_ESumS>0)
            {
                hTimevsTSum_AT->Fill(time,APPT_TSum);
                hEkESMa->Fill(missing.E()-missing.M(),APPT_ESumS-0.5,missing.M(),time);
                hTiESMa->Fill(time-APPT_TSum,APPT_ESumS-0.5,missing.M(),time);
            }

            if (verbosity>1) printf("%.2f\t\t%.2f\t%.2f\t\t%.2f\t%.2f\n",pi0_time,pi0.M(),pi0_theta,pi0_theta_cm,pi0_phi);

            if((TMath::Abs(pi0_phi)>=45) && (TMath::Abs(pi0_phi)<135) && pi0_theta>15 && pi0_theta<=165)
            {
                if(pi0_phi>0)
                {
                    if(hel) hChThMa_Hel1->Fill(beam_channel,pi0_theta,missing.M(),time);
                    else hChThMa_Hel0->Fill(beam_channel,pi0_theta,missing.M(),time);
                }
                else
                {
                    if(hel) hChThMa_Hel0->Fill(beam_channel,pi0_theta,missing.M(),time);
                    else hChThMa_Hel1->Fill(beam_channel,pi0_theta,missing.M(),time);
                }
                hChThMa_HelS->FillWeighted(beam_channel,pi0_theta,missing.M(),(beam_pol*(gTheory->Interpolate(beam_energy,pi0_theta_cm))),time);
            }

            // Additional cut to ensure that the missing particle is the proton
            //if ((TMath::Abs(missing.M()-938.27) > 50) || (missing_theta < 25) || (missing.E()-missing.M() < 60)) continue;

            // Loop over all rootinos
            for (Int_t k = 0; k < GetRootinos()->GetNParticles(); k++)
            {
                // Determine proton kinematics, and fill related histograms
                proton_theta = GetRootinos()->GetTheta(k);
                opening = (TMath::RadToDeg()*missing.Angle(GetRootinos()->GetUnitVector(k)));
                hEkOAMa->Fill(missing.E()-missing.M(),opening,missing.M(),time);
                if(APPT_ESumS>0) hEkOAMa_AT->Fill(missing.E()-missing.M(),opening,missing.M(),time);

                if (verbosity>1) printf("%.2f\t\t%.2f\t%.2f\t\t%.2f\t%.2f\t\t%.2f\n",missing.E()-missing.M(),missing.Theta()*TMath::RadToDeg(),GetRootinos()->GetUnitVector(k).Theta()*TMath::RadToDeg(),missing.Phi()*TMath::RadToDeg(),GetRootinos()->GetUnitVector(k).Phi()*TMath::RadToDeg(),(TMath::RadToDeg()*missing.Angle(GetRootinos()->GetUnitVector(k))));

                // Check if event satisifes an opening angle cut between the expected and detected proton
                if (opening < OACut)
                {
                    hTime_OA->Fill(time);
                    if((GHistBGSub::IsPrompt(time)) || (GHistBGSub::IsRandom(time))) hTCut_OA->Fill(time);

                    hEkThMa_OA->Fill(missing.E()-missing.M(),missing_theta,missing.M(),time);
                    hEkEHMa_OA->Fill(missing.E()-missing.M(),APPT_ESumH-0.5,missing.M(),time);
                    hTiEHMa_OA->Fill(time-APPT_TSum,APPT_ESumH-0.5,missing.M(),time);
                    if(APPT_ESumS>0)
                    {
                        hEkESMa_OA->Fill(missing.E()-missing.M(),APPT_ESumS-0.5,missing.M(),time);
                        hTiESMa_OA->Fill(time-APPT_TSum,APPT_ESumS-0.5,missing.M(),time);
                    }

                    // Check if rootino was tagged as charged
                    if (GetRootinos()->IsCharged(k))
                    {
                        hTime_Ch->Fill(time);
                        if((GHistBGSub::IsPrompt(time)) || (GHistBGSub::IsRandom(time))) hTCut_Ch->Fill(time);

                        hEkThMa_Ch->Fill(missing.E()-missing.M(),missing_theta,missing.M(),time);
                        hEkEHMa_Ch->Fill(missing.E()-missing.M(),APPT_ESumH-0.5,missing.M(),time);
                        hTiEHMa_Ch->Fill(time-APPT_TSum,APPT_ESumH-0.5,missing.M(),time);
                        if(APPT_ESumS>0)
                        {
                            hEkESMa_Ch->Fill(missing.E()-missing.M(),APPT_ESumS-0.5,missing.M(),time);
                            hTiESMa_Ch->Fill(time-APPT_TSum,APPT_ESumS-0.5,missing.M(),time);
                        }
                    }
                }
            }
        }
    }

    // Fill invariant mass, all pi0
    FillMass(*GetNeutralPions(),hIM);

    // Fill missing mass, all pi0
    FillMissingMass(*GetNeutralPions(),hMM);

}

Bool_t 	PActive::InitVerbosity()
{
    Int_t sc1;
    string config = ReadConfig("Verbosity");
    if(sscanf( config.c_str(), "%d\n", &sc1) == 1)
    {
        cout << "Setting verbosity: " << sc1 << endl << endl;
        verbosity = sc1;
    }
    else if(strcmp(config.c_str(), "nokey") != 0)
    {
        cout << "Verbosity not set correctly" << endl << endl;
        return kFALSE;
    }

    return kTRUE;

}

Bool_t 	PActive::InitExclusivity()
{
    Int_t sc1, sc2;
    string config = ReadConfig("Exclusivity");
    if(sscanf( config.c_str(), "%d%d\n", &sc1, &sc2) == 2)
    {
        cout << "Setting exclusivity: pi0 = " << sc1 << ", p = " << sc2 << endl << endl;
        excl_pi0 = sc1;
        excl_pro = sc2;
    }
    else if(strcmp(config.c_str(), "nokey") != 0)
    {
        cout << "Exclusivity not set correctly" << endl << endl;
        return kFALSE;
    }

    return kTRUE;

}

Bool_t 	PActive::InitOpeningAngle()
{
    Double_t sc1;
    string config = ReadConfig("Opening-Angle-Cut");
    if(sscanf( config.c_str(), "%lf\n", &sc1) == 1)
    {
        cout << "Setting opening angle: " << sc1 << " deg " << endl << endl;
        OACut = sc1;
    }
    else if(strcmp(config.c_str(), "nokey") != 0)
    {
        cout << "Opening angle cut not set correctly" << endl << endl;
        return kFALSE;
    }

    return kTRUE;

}

Bool_t 	PActive::InitActiveChannel()
{
    string config;
    Int_t instance = 0;
    do
    {
        Int_t sc1;
        Double_t sc2, sc3, sc4, sc5;
        Int_t sc6;
        config = ReadConfig("Active-Channel", instance);
        if(sscanf( config.c_str(), "%d%lf%lf%lf%lf%d\n", &sc1, &sc2, &sc3, &sc4, &sc5, &sc6) == 6)
        {
            cout << "Setting active channel " << sc1 << ": ADC Ped = " << sc2 << ", ADC Gain = " << sc3 << ", TDC Off = " << sc4 << ", TDC Gain = " << sc5 << ", Sum? " << sc6 << endl << endl;
            APPT_ADC_Ped[sc1] = sc2;
            APPT_ADC_Gain[sc1] = sc3;
            APPT_TDC_Off[sc1] = sc4;
            APPT_TDC_Gain[sc1] = sc5;
            APPT_Use[sc1] = sc6;
        }
        else if(strcmp(config.c_str(), "nokey") != 0)
        {
            cout << "Active channel not set correctly" << endl << endl;
            return kFALSE;
        }
        instance++;
    } while (strcmp(config.c_str(), "nokey") != 0);

    return kTRUE;

}

Bool_t 	PActive::InitActiveScale()
{
    Double_t sc1;
    string config = ReadConfig("Active-Scale");
    if(sscanf( config.c_str(), "%lf\n", &sc1) == 1)
    {
        cout << "Setting active scale: " << sc1 << endl << endl;
        APPT_Scale = sc1;
    }
    else if(strcmp(config.c_str(), "nokey") != 0)
    {
        cout << "Active scale not set correctly" << endl << endl;
        return kFALSE;
    }

    return kTRUE;

}

Double_t PActive::CalcCircBeamPol(Double_t E_e, Double_t P_e, Double_t E_g)
{
    Double_t P_g = P_e*(((4*E_g*E_e)-(E_g*E_g))/((4*E_e*E_e)-(4*E_g*E_e)+(3*E_g*E_g)));

    return P_g;
}

void	PActive::ProcessScalerRead()
{
    PPhysics::ProcessScalerRead();
}

Bool_t	PActive::Write()
{
    // Write all GH1's and TObjects defined in this class
    return GTreeManager::Write();
}
