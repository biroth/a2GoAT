#ifndef __PActive_h__
#define __PActive_h__

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

#include "GTreeManager.h"
#include "PPhysics.h"

class	PActive  : public PPhysics
{
private:
    GH1*	time;
    GH1*	time_cut;
    GH1*	time_2g;      
    GH1*	time_2g_cut;   
     
    GH1*	IM;
    GH1*	IM_2g;

    GH1*	MM;
    GH1*	MM_2g;

    Int_t APPT_ADC[16];
    Int_t APPT_TDC[16];

    Double_t APPT_Ener[16];
    Double_t APPT_Time[16];
    Double_t APPT_ESum;

    TH1D*   hAPPT_Ener[16];
    TH1D*   hAPPT_Time[16];
    TH2D*   hAPPT_EvsT[16];
    TH1D*   hAPPT_ESum;
    TH2D*   hAPPT_TSum;

protected:
    virtual Bool_t  Start();
    virtual void    ProcessEvent();
    virtual void	ProcessScalerRead();
    virtual Bool_t    Write();
			
public:
    PActive();
    virtual ~PActive();
    virtual Bool_t  Init();

};
#endif
