import FWCore.ParameterSet.Config as cms

process = cms.Process("rpcEfficiencyStep2")
# process.load("Geometry.MuonCommonData.muonIdealGeometryXML_cfi")
process.load('Configuration.Geometry.GeometryExtended2015Reco_cff')
process.load('Configuration.Geometry.GeometryExtended2015_cff')

process.load("Geometry.RPCGeometry.rpcGeometry_cfi")
process.load("Geometry.MuonNumbering.muonNumberingInitialization_cfi")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
    )
process.source = cms.Source("EmptySource")

process.MessageLogger = cms.Service("MessageLogger")

process.rpcEfficiencyStep2 = cms.EDAnalyzer("RPCMonitorEfficiency",
                                            fileInName = cms.untracked.string(

'file:Efficiency_2018_RPCMon.root',

),
                                            fileOutName = cms.untracked.string(
'AnalyzeEfficiency_XXXXXX_RPCMon.root'

),
                                            
                                            saveRollInputHistograms  = cms.untracked.bool(True),                             
                                            saveRollEfficiencyHistograms  = cms.untracked.bool(True),                             
                                            debug = cms.untracked.bool(True),
                                            minimumExtrapolatedHits  = cms.untracked.int32(1),
                                            fiducialcut  = cms.untracked.double(8.0)

                                            )

process.p = cms.Path(process.rpcEfficiencyStep2)








