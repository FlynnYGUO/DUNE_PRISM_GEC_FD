# Learn how to manipulate Geometric Efficiency Corrections step by step
## 1. Add some branches into the FD ntuple
> - Details of some variables: https://internal.dunescience.org/doxygen/MCNeutrino_8h_source.html#l00018
> - Example of how to access CCNC: https://github.com/DUNE/dunetpc/blob/master/dune/FDSensOpt/NueAna_module.cc#L655-L656  
- Update [```MyEnergyAnalysis_module.cc```](https://github.com/FlynnYGUO/myntuples/blob/main/myntuples/MyEnergyAnalysis/MyEnergyAnalysis_module.cc), then follow this to get new FD ntuple root file: https://github.com/FlynnYGUO/DUNE_PRISM#3-recompile-and-rerun   
- Execute [```FDplot.cpp```](https://github.com/FlynnYGUO/DUNE_PRISM/blob/main/Steps/Step1/FDplot.cpp) to draw several plots from [```myntuple.root```](https://github.com/FlynnYGUO/DUNE_PRISM/blob/main/Steps/Step1/myntuple.root) with specific requirements.
- Run [```NtupleCounter.cpp```](https://github.com/FlynnYGUO/DUNE_PRISM/blob/main/Steps/Step1/NtupleCounter.cpp) to get the number of occurrences of some elements, like CCNC, Interaction Type, Mode, True Neutrino Energy, etc. in this root file.
