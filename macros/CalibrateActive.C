void CalibrateActive(TString sFile, Int_t nPoints=6){
  TFile f1(sFile,"READ");
  TTree *t1 = (TTree*)f1.Get("detectorHits");

  sFile.ReplaceAll("Acqu_","APPT_");
  sFile.ReplaceAll(".root",".txt");
  FILE* log = fopen(sFile.Data(),"w+");

  gROOT->cd();
  //gStyle->SetOptStat(0);
  TH1D *h1[16];
  TF1 *fit[16][8];
  TLine *p1[16][8];
  TGraph *g1[16];
  TF1 *l1[16];

  TCanvas *c1 = new TCanvas("c1","APPT Calibration");
  c1->Divide(4,4);

  for(Int_t i=0; i<16; i++){
    h1[i] = new TH1D(Form("h%d",i),Form("ADC %d",i),2000,0,2000);
    g1[i] = new TGraph(nPoints);
    l1[i] = new TF1(Form("l%d",i),"pol1",-1,nPoints);

    t1->Project(Form("h%d",i),Form("APPT_ADC%d",i+1));
    Double_t lo = h1[i]->GetMaximum();
    Double_t hi = h1[i]->GetMinimum();
    Double_t pk = 0;

    for(Int_t j=0; j<nPoints; j++){
      pk = h1[i]->GetMaximumBin()-1;
      fit[i][j] = new TF1(Form("fit_%d_%d",i,j),"gaus",0,2000);
      fit[i][j]->SetParameters(h1[i]->GetMaximum(),pk,10);
      h1[i]->Fit(Form("fit_%d_%d",i,j),"QN","",pk-7,pk+7);
      pk = TMath::Nint(fit[i][j]->GetParameter(1));
      p1[i][j] = new TLine(pk,lo,pk,hi);
      g1[i]->SetPoint(j,j,pk);
      h1[i]->GetXaxis()->SetRange(pk+50,2000);
    }
    h1[i]->GetXaxis()->SetRange(p1[i][0]->GetX1()-100,p1[i][nPoints-1]->GetX1()+100);
    g1[i]->Fit(Form("l%d",i),"Q");
    fprintf(log, "%.1f\t%.5f\n", l1[i]->GetParameter(0), 1/(l1[i]->GetParameter(1)));
    cout << l1[i]->GetParameter(0) << "\t" << 1/(l1[i]->GetParameter(1)) << endl;
    c1->cd(i+1);
    c1->GetPad(i+1)->SetLogy();
    h1[i]->SetLineColor(4);
    h1[i]->DrawClone();
    for(Int_t j=0; j<nPoints; j++) p1[i][j]->Draw();
  }
  sFile.ReplaceAll(".txt",".pdf");
  c1->SaveAs(sFile);
  sFile.ReplaceAll(".pdf",".root");
  c1->SaveAs(sFile);
  fclose(log);
}
