import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")
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

process.effSummary = cms.EDAnalyzer("RPCSummaryEfficiency",
                                    fileName = cms.untracked.string('AnalyzeEfficiency_XXXXXX_RPCMon.root'),
                                    fileOut = cms.untracked.string('SummaryAnalyzeEfficiency_XXXXXX_RPCMon.root' ),
                                    
                                    debug = cms.untracked.bool(True),
                                    barrel = cms.untracked.bool(True),
                                    endcap = cms.untracked.bool(True),

                                    useBlackList = cms.untracked.bool(True),
                                    BlackListFile = cms.untracked.string('blackList.txt' ),

                                    useWhiteList = cms.untracked.bool(True),
                                    WhiteListFile = cms.untracked.string('whiteList.txt' )
                                    )

process.p = cms.Path(process.effSummary)






