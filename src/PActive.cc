#include "PActive.h"

PActive::PActive()
{ 
    TaggerAllHits = new TH1D("TaggerAllHits", "Tagger - All Hits", 352, 0, 352);
    TaggerSingles = new TH1D("TaggerSingles", "Tagger - Single Hits", 352, 0, 352);
    TaggerDoubles = new TH1D("TaggerDoubles", "Tagger - Double Hits", 352, 0, 352);

    NePi_Time = new TH1D("NePi_Time", "Neutral Pion Time;t_{#gamma}-t_{#pi^{0}} (ns)", 1400, -700, 700);
    NePi_TCut = new TH1D("NePi_TCut", "Neutral Pion Time;t_{#gamma}-t_{#pi^{0}} (ns)", 1400, -700, 700);
    NePi_EkEHMa = new GH3("NePi_EkEHMa", "Neutral Pion Missing Mass;Ek_{miss} (MeV);APPT ESum Hardware;m_{miss} (MeV)", 100, 0, 200, 25, 0, 25, 80, 800, 1200);
    NePi_EkESMa = new GH3("NePi_EkESMa", "Neutral Pion Missing Mass;Ek_{miss} (MeV);APPT ESum Software;m_{miss} (MeV)", 100, 0, 200, 25, 0, 25, 80, 800, 1200);
    NePi_TiEHMa = new GH3("NePi_TiEHMa", "Neutral Pion Missing Mass;t_{#gamma}-t_{#pi^{0}}-t_{AT} (ns);APPT ESum Hardware;m_{miss} (MeV)", 200, -1000, 1000, 25, 0, 25, 80, 800, 1200);
    NePi_TiESMa = new GH3("NePi_TiESMa", "Neutral Pion Missing Mass;t_{#gamma}-t_{#pi^{0}}-t_{AT} (ns);APPT ESum Software;m_{miss} (MeV)", 200, -1000, 1000, 25, 0, 25, 80, 800, 1200);

    NePi_Time_OA = new TH1D("NePi_Time_OA", "Neutral Pion Time;t_{#gamma}-t_{#pi^{0}} (ns)", 1400, -700, 700);
    NePi_TCut_OA = new TH1D("NePi_TCut_OA", "Neutral Pion Time;t_{#gamma}-t_{#pi^{0}} (ns)", 1400, -700, 700);
    NePi_EkEHMa_OA = new GH3("NePi_EkEHMa_OA", "Neutral Pion Missing Mass;Ek_{miss} (MeV);APPT ESum Hardware;m_{miss} (MeV)", 100, 0, 200, 25, 0, 25, 80, 800, 1200);
    NePi_EkESMa_OA = new GH3("NePi_EkESMa_OA", "Neutral Pion Missing Mass;Ek_{miss} (MeV);APPT ESum Software;m_{miss} (MeV)", 100, 0, 200, 25, 0, 25, 80, 800, 1200);
    NePi_TiEHMa_OA = new GH3("NePi_TiEHMa_OA", "Neutral Pion Missing Mass;t_{#gamma}-t_{#pi^{0}}-t_{AT} (ns);APPT ESum Hardware;m_{miss} (MeV)", 200, -1000, 1000, 25, 0, 25, 80, 800, 1200);
    NePi_TiESMa_OA = new GH3("NePi_TiESMa_OA", "Neutral Pion Missing Mass;t_{#gamma}-t_{#pi^{0}}-t_{AT} (ns);APPT ESum Software;m_{miss} (MeV)", 200, -1000, 1000, 25, 0, 25, 80, 800, 1200);

    NePi_EkOAMa = new GH3("NePi_EkOAMa", "Neutral Pion Missing Mass;Ek_{miss} (MeV);Opening Angle (deg);m_{miss} (MeV)", 100, 0, 200, 36, 0, 180, 80, 800, 1200);
    NePi_EkOAMa_AT = new GH3("NePi_EkOAMa_AT", "Neutral Pion Missing Mass;Ek_{miss} (MeV);Opening Angle (deg);m_{miss} (MeV)", 100, 0, 200, 36, 0, 180, 80, 800, 1200);

    IM 		= new GH1("IM", 	"IM", 		400,   0, 400);
    MM		= new GH1("MM", 	"MM", 	 	400,   800, 1200);

    TimevsTSum = new TH2D("TimevsTSum", "Neutral Pion Time;t_{#gamma}-t_{#pi^{0}} (ns);APPT Time (ns)", 1400, -700, 700, 200, -1000, 1000);
    TimevsTSum_AT = new TH2D("TimevsTSum_AT", "Neutral Pion Time;t_{#gamma}-t_{#pi^{0}} (ns);APPT Time (ns)", 1400, -700, 700, 200, -1000, 1000);

    OACut = 180;

    for(Int_t i=0; i<16; i++)
    {
        APPT_ADC[i] = 0;
        APPT_TDC[i] = 0;

        APPT_ADC_Ped[i] = 600;
        APPT_ADC_Gain[i] = 0.01;
        APPT_TDC_Off[i] = -20000;
        APPT_TDC_Gain[i] = 0.1;

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
    if(!InitOpeningAngle()) return kFALSE;
    if(!InitActiveChannel()) return kFALSE;
    if(!InitActiveScale()) return kFALSE;

    if(!PPhysics::Init()) return kFALSE;

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
    APPT_ESumS = 0;
    for(Int_t i=0; i<15; i++)
    {
        APPT_Ener[i] = APPT_ADC_Gain[i]*(APPT_ADC[i]-APPT_ADC_Ped[i]);
        APPT_Time[i] = APPT_TDC_Gain[i]*(APPT_TDC[i]-APPT_TDC_Off[i]);

        if(APPT_Ener[i]<0.5) continue;
        hAPPT_Ener[i]->Fill(APPT_Ener[i]);
        hAPPT_Time[i]->Fill(APPT_Time[i]);
        hAPPT_EvsT[i]->Fill(APPT_Time[i],APPT_Ener[i]);

        if(i<14) APPT_ESumS += APPT_Ener[i];
    }
    APPT_ESumH = APPT_ADC_Gain[15]*(APPT_ADC[15]-APPT_ADC_Ped[15]);
    APPT_TSum = APPT_TDC_Gain[15]*(APPT_TDC[15]-APPT_TDC_Off[15]);
    hAPPT_TSum->Fill(APPT_TSum);
    hAPPT_ESumH->Fill(APPT_ESumH);
    hAPPT_EHvsT->Fill(APPT_TSum,APPT_ESumH);

    if(APPT_ESumS>0)
    {
        APPT_ESumS = APPT_ESumS*APPT_Scale;
        hAPPT_ESumS->Fill(APPT_ESumS);
        hAPPT_ESvsT->Fill(APPT_TSum,APPT_ESumS);
    }
    hAPPT_EHvsES->Fill(APPT_ESumS+0.5,APPT_ESumH+0.5);

    //if ((GetNeutralPions()->GetNParticles() == 1) && (GetRootinos()->GetNParticles() == 1))
    if (GetNeutralPions()->GetNParticles() == 1)
    {
    Double_t tagg_time, time, theta, opening;
    TLorentzVector beam, target, pi_zero, recoil, missing;
    target = GetTarget();
    pi_zero = GetNeutralPions()->Particle(0);
    //pi_zero = GetNeutralPions()->GetVector(0,134.98);
    //theta = GetNeutralPions()->GetTheta(0);

    if(GetDecodeDoubles()) GetTagger()->DecodeDoubles();

    Int_t nTagg = GetTagger()->GetNTagged();
    Int_t nDoub = GetTagger()->GetNDouble();

    //if (GetEventNumber()%100000 == 0) cout << endl << "Event " << GetEventNumber() << endl;

    for (Int_t i = 0; i < (nTagg+nDoub); i++)
    {
        if (i < nTagg)
        {
            TaggerAllHits->Fill(GetTagger()->GetTaggedChannel(i));
            if (RejectTagged(i)) continue;
            TaggerSingles->Fill(GetTagger()->GetTaggedChannel(i));
            TaggerDoubles->Fill(GetTagger()->GetTaggedChannel(i));

            tagg_time = GetTagger()->GetTaggedTime(i);
            beam = TLorentzVector(0., 0., GetTagger()->GetTaggedEnergy(i), GetTagger()->GetTaggedEnergy(i));
            //cout << endl << "Tagger Channel = " << GetTagger()->GetTaggedChannel(i) << "\tTagged Energy = " << GetTagger()->GetTaggedEnergy(i) << endl << endl;
        }
        else
        {
            if (RejectDouble(i-nTagg)) continue;
            TaggerDoubles->Fill(GetTagger()->GetDoubleRandom(i-nTagg));

            tagg_time = GetTagger()->GetDoubleTime(i-nTagg);
            beam = TLorentzVector(0., 0., GetTagger()->GetDoubleEnergy(i-nTagg), GetTagger()->GetDoubleEnergy(i-nTagg));

            //cout << endl << "Double Channel = " << GetTagger()->GetDoubleRandom(i-nTagg) << "\tTagged Energy = " << GetTagger()->GetDoubleEnergy(i-nTagg) << endl << endl;
        }

        time = tagg_time - GetNeutralPions()->GetTime(0);
        missing = beam + target - pi_zero;
        theta = missing.Theta()*TMath::RadToDeg();
        NePi_Time->Fill(time);
        TimevsTSum->Fill(time,APPT_TSum);
        if((GHistBGSub::IsPrompt(time)) || (GHistBGSub::IsRandom(time))) NePi_TCut->Fill(time);
        NePi_EkEHMa->Fill(missing.E()-missing.M(),APPT_ESumH-0.5,missing.M(),time);
        NePi_TiEHMa->Fill(time-APPT_TSum,APPT_ESumH-0.5,missing.M(),time);
        if(APPT_ESumS>0)
        {
            TimevsTSum_AT->Fill(time,APPT_TSum);
            NePi_EkESMa->Fill(missing.E()-missing.M(),APPT_ESumS-0.5,missing.M(),time);
            NePi_TiESMa->Fill(time-APPT_TSum,APPT_ESumS-0.5,missing.M(),time);
        }
        hAPPT_EHvsES_NePi->Fill(APPT_ESumS+0.5,APPT_ESumH+0.5);
        if ((TMath::Abs(missing.M()-938.27) > 50) || (theta < 25) || (missing.E()-missing.M() < 60)) continue;
        for (Int_t j = 0; j < GetRootinos()->GetNParticles(); j++)
        {
            opening = (TMath::RadToDeg()*missing.Angle(GetRootinos()->GetUnitVector(j)));
            //printf("%.2f\t\t%.2f\t%.2f\t\t%.2f\t%.2f\t\t%.2f\n",missing.E()-missing.M(),missing.Theta()*TMath::RadToDeg(),GetRootinos()->GetUnitVector(j).Theta()*TMath::RadToDeg(),missing.Phi()*TMath::RadToDeg(),GetRootinos()->GetUnitVector(j).Phi()*TMath::RadToDeg(),(TMath::RadToDeg()*missing.Angle(GetRootinos()->GetUnitVector(j))));
            NePi_EkOAMa->Fill(missing.E()-missing.M(),opening,missing.M(),time);
            if(APPT_ESumS>0) NePi_EkOAMa_AT->Fill(missing.E()-missing.M(),opening,missing.M(),time);
            if (opening < OACut)
            {
                NePi_Time_OA->Fill(time);
                if((GHistBGSub::IsPrompt(time)) || (GHistBGSub::IsRandom(time))) NePi_TCut_OA->Fill(time);
                NePi_EkEHMa_OA->Fill(missing.E()-missing.M(),APPT_ESumH-0.5,missing.M(),time);
                NePi_TiEHMa_OA->Fill(time-APPT_TSum,APPT_ESumH-0.5,missing.M(),time);
                if(APPT_ESumS>0)
                {
                    NePi_EkESMa_OA->Fill(missing.E()-missing.M(),APPT_ESumS-0.5,missing.M(),time);
                    NePi_TiESMa_OA->Fill(time-APPT_TSum,APPT_ESumS-0.5,missing.M(),time);
                }
            }
        }
    }
    }
	
	// fill invariant mass, all pi0
    FillMass(*GetNeutralPions(),IM);

    // fill missing mass, all pi0
    FillMissingMass(*GetNeutralPions(),MM);

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
        config = ReadConfig("Active-Channel", instance);
        if(sscanf( config.c_str(), "%d%lf%lf%lf%lf\n", &sc1, &sc2, &sc3, &sc4, &sc5) == 5)
        {
            cout << "Setting active channel " << sc1 << ": ADC Ped = " << sc2 << ", ADC Gain = " << sc3 << ", TDC Off = " << sc4 << ", TDC Gain = " << sc5 << endl << endl;
            APPT_ADC_Ped[sc1] = sc2;
            APPT_ADC_Gain[sc1] = sc3;
            APPT_TDC_Off[sc1] = sc4;
            APPT_TDC_Gain[sc1] = sc5;
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

void	PActive::ProcessScalerRead()
{
    PPhysics::ProcessScalerRead();
}

Bool_t	PActive::Write()
{
    // Write all GH1's and TObjects defined in this class
    return GTreeManager::Write();
}
