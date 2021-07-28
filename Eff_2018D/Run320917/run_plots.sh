cmsRun calculateEfficiency.py
cmsRun makeEfficiencySummary.py
root -l -b<<EOS
.L EndcapPlot.C
.L WheelPlot.C 
.x drawEfficiencyHistograms.C("SummaryAnalyzeEfficiency_XXXXXX_RPCMon.root")
EOS

