#include "PActive.h"

PActive::PActive()
{ 
    time 	= new GH1("time", 	"time", 	1400, -700, 700);
    time_cut 	= new GH1("time_cut", 	"time_cut", 	1400, -700, 700);

    time_2g 	= new GH1("time_2g",	"time_2g", 	1400, -700, 700);
    time_2g_cut = new GH1("time_2g_cut","time_2g_cut", 	1400, -700, 700);

    IM 		= new GH1("IM", 	"IM", 		400,   0, 400);
    IM_2g 	= new GH1("IM_2g", 	"IM_2g", 	400,   0, 400);
  
    MM		= new GH1("MM", 	"MM", 	 	400,   800, 1200);     
    MM_2g	= new GH1("MM_2g", 	"MM_2g", 	400,   800, 1200);


    for(Int_t i=0; i<16; i++)
    {
        APPT_ADC[i] = 0;
        APPT_TDC[i] = 0;
        APPT_Ener[i] = 0;
        APPT_Time[i] = 0;
        hAPPT_Ener[i] = new TH1D(Form("hAPPT_Ener%d",i+1),Form("APPT %02d Energy;Energy (#Photons)",i+1),200,0,20);
        hAPPT_Time[i] = new TH1D(Form("hAPPT_Time%d",i+1),Form("APPT %02d Time;Time (ns)",i+1),200,-1000,1000);
        hAPPT_EvsT[i] = new TH2D(Form("hAPPT_EvsT%d",i+1),Form("APPT %02d Energy vs Time;Time (ns);Energy (#Photons)",i+1),200,-1000,1000,200,0,20);
    }
    APPT_ESum = 0;
    hAPPT_ESum = new TH1D("hAPPT_ESum","APPT Energy Sum;Energy (#Photons)",200,0,20);
    hAPPT_TSum = new TH2D("hAPPT_TSum","APPT Energy Sum vs Time;Time (ns);Energy (#Photons)",200,-1000,1000,200,0,20);
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

    if(!PPhysics::Init()) return kFALSE;

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

    return kTRUE;
}

void	PActive::ProcessEvent()
{
    // Uncomment the following line to decode double hits in the tagger
    //GetTagger()->DecodeDoubles();

    // fill time diff (tagger - pi0), all pi0
    FillTime(*GetNeutralPions(),time);
    FillTimeCut(*GetNeutralPions(),time_cut);
	
	// fill missing mass, all pi0
    FillMissingMass(*GetNeutralPions(),MM);
	
	// fill invariant mass, all pi0
    FillMass(*GetNeutralPions(),IM);
		
    // Some neutral decays
    for (Int_t i = 0; i < GetNeutralPions()->GetNParticles(); i++)
    {
        // Fill MM for 2 photon decay
        if ((GetNeutralPions()->GetNSubParticles(i) == 2) & (GetNeutralPions()->GetNSubPhotons(i) == 2))
        {
		// fill time diff (tagger - pi0), this pi0
        FillTime(*GetNeutralPions(),i,time_2g);
        FillTimeCut(*GetNeutralPions(),i,time_2g_cut);
			
		// fill missing mass, this pi0
                FillMissingMass(*GetNeutralPions(),i,MM_2g);
            
		// fill invariant mass, this pi0
            FillMass(*GetNeutralPions(),i,IM_2g);
        }

    }

    //Double_t APPT_ADC_Ped[16] = {661.6, 509.1, 569.1, 600.0, 576.9, 550.2, 585.1, 574.6, 592.1, 556.6, 549.9, 567.2, 566.9, 584.9, 600.0, 600.0}; // Jan 2016
    //Double_t APPT_ADC_Gain[16] = {0.0116, 0.0138, 0.0109, 0.0120, 0.0108, 0.0116, 0.0129, 0.0126, 0.0124, 0.0121, 0.0119, 0.0125, 0.0133, 0.0125, 0.012, 0.012}; // Jan 2016

    //Double_t APPT_ADC_Ped[16] = {664.7, 597.0, 597.5, 563.2, 606.7, 546.3, 628.7, 608.5, 596.5, 560.5, 552.2, 575.0, 555.3, 588.8, 568.2, 930.5}; // Mar 2016 run 13172-13173
    //Double_t APPT_ADC_Gain[16] = {0.00909, 0.00901, 0.00889, 0.00948, 0.00833, 0.01087, 0.01010, 0.00948, 0.00948, 0.00957, 0.00922, 0.00952, 0.01020, 0.00939, 0.01036, 0.02062}; // Mar 2016 run 13172-13173

    //Double_t APPT_ADC_Ped[16] = {663.0, 594.6, 594.2, 560.2, 606.6, 546.2, 627.2, 607.8, 595.0, 558.0, 550.8, 572.8, 550.4, 586.0, 569.9, 1770.0}; // Mar 2016 run 13175-13186
    //Double_t APPT_ADC_Gain[16] = {0.01086, 0.01071, 0.01031, 0.01103, 0.00994, 0.01271, 0.01160, 0.01111, 0.01117, 0.01100, 0.01093, 0.01134, 0.01190, 0.01101, 0.01291, 0.02237}; // Mar 2016 run 13175-13186

    //Double_t APPT_ADC_Ped[16] = {669.8, 602.7, 601.8, 568.7, 604.3, 537.3, 620.3, 593.5, 597.5, 562.8, 553.0, 576.2, 564.0, 587.8, 576.3, 1786.0}; // Mar 2016 run 13189
    //Double_t APPT_ADC_Gain[16] = {0.00683, 0.00680, 0.00678, 0.00719, 0.00625, 0.00813, 0.00775, 0.00727, 0.00727, 0.00738, 0.00704, 0.00712, 0.00787, 0.00712, 0.00820, 0.02273}; // Mar 2016 run 13189

    //Double_t APPT_ADC_Ped[16] = {668.3, 602.0, 601.5, 568.7, 603.5, 537.2, 620.3, 593.5, 597.2, 562.5, 553.8, 576.0, 563.5, 587.8, 576.7, 1783.3}; // Mar 2016 run 13190
    //Double_t APPT_ADC_Gain[16] = {0.00862, 0.00885, 0.00881, 0.00943, 0.00803, 0.01058, 0.01020, 0.00948, 0.00939, 0.00957, 0.00930, 0.00926, 0.01026, 0.00922, 0.01075, 0.02273}; // Mar 2016 run 13190

    Double_t APPT_ADC_Ped[16] = {666.4, 598.4, 595.0, 562.6, 601.0, 533.0, 613.4, 589.2, 594.0, 556.6, 548.8, 573.6, 558.0, 585.2, 570.8, 1783.0}; // Mar 2016 run 13191-13194
    Double_t APPT_ADC_Gain[16] = {0.00988, 0.00981, 0.00951, 0.01011, 0.00912, 0.01161, 0.01080, 0.01029, 0.01038, 0.01031, 0.01009, 0.01054, 0.01105, 0.01035, 0.01143, 0.02525}; // Mar 2016 run 13191-13194

//    Double_t APPT_TDC_Off[16] = {-21300, -21300, -21300, -21300, -21300, -21300, -21300, -21300, -21300, -21300, -21300, -21300, -21300, -21300, -21300, -21300};
    Double_t APPT_TDC_Off[16] = {-20000, -20000, -20000, -20000, -20000, -20000, -20000, -20000, -20000, -20000, -20000, -20000, -20000, -20000, -20000, -20000};
    Double_t APPT_TDC_Gain = 0.1;

    APPT_ESum = 0;
    for(Int_t i=0; i<16; i++)
    {
        APPT_Ener[i] = APPT_ADC_Gain[i]*(APPT_ADC[i]-APPT_ADC_Ped[i]);
        APPT_Time[i] = APPT_TDC_Gain*(APPT_TDC[i]-APPT_TDC_Off[i]);

        if(APPT_Ener[i]<0.5) continue;
        hAPPT_Ener[i]->Fill(APPT_Ener[i]);
        hAPPT_Time[i]->Fill(APPT_Time[i]);
	hAPPT_EvsT[i]->Fill(APPT_Time[i],APPT_Ener[i]);

        if(i<14) APPT_ESum += APPT_Ener[i];
    }
    if(APPT_ESum>0)
    {
        hAPPT_ESum->Fill(APPT_ESum);
        hAPPT_TSum->Fill(APPT_Time[15],APPT_ESum);
    }

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
