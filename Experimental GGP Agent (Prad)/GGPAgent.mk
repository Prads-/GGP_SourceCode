##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=GGPAgent
ConfigurationName      :=Debug
WorkspacePath          := "/home/prads/Documents/ProgProjects/My Projects"
ProjectPath            := "/home/prads/Documents/ProgProjects/My Projects/GGPAgent"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Prads
Date                   :=12/05/14
CodeLitePath           :="/home/prads/.codelite"
LinkerName             :=/usr/bin/g++ 
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="GGPAgent.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++ 
CC       := /usr/bin/gcc 
CXXFLAGS :=  -g -O0 -Wall -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Tokenizer.cpp$(ObjectSuffix) $(IntermediateDirectory)/Token.cpp$(ObjectSuffix) $(IntermediateDirectory)/TokenLiner.cpp$(ObjectSuffix) $(IntermediateDirectory)/TokenLine.cpp$(ObjectSuffix) $(IntermediateDirectory)/SymbolTable.cpp$(ObjectSuffix) $(IntermediateDirectory)/Symbol.cpp$(ObjectSuffix) $(IntermediateDirectory)/IfNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/GDLNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/LegalNode.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/TrueNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/NotNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/NextNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/OrNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/TerminalNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/GoalNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/RuleNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/PropositionNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/BaseNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/InputNode.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/DistinctNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/DoesNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/InitNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/AST.cpp$(ObjectSuffix) $(IntermediateDirectory)/RelationNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/RoleNode.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Tokenizer.cpp$(ObjectSuffix): Tokenizer.cpp $(IntermediateDirectory)/Tokenizer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/Tokenizer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Tokenizer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Tokenizer.cpp$(DependSuffix): Tokenizer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Tokenizer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Tokenizer.cpp$(DependSuffix) -MM "Tokenizer.cpp"

$(IntermediateDirectory)/Tokenizer.cpp$(PreprocessSuffix): Tokenizer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Tokenizer.cpp$(PreprocessSuffix) "Tokenizer.cpp"

$(IntermediateDirectory)/Token.cpp$(ObjectSuffix): Token.cpp $(IntermediateDirectory)/Token.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/Token.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Token.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Token.cpp$(DependSuffix): Token.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Token.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Token.cpp$(DependSuffix) -MM "Token.cpp"

$(IntermediateDirectory)/Token.cpp$(PreprocessSuffix): Token.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Token.cpp$(PreprocessSuffix) "Token.cpp"

$(IntermediateDirectory)/TokenLiner.cpp$(ObjectSuffix): TokenLiner.cpp $(IntermediateDirectory)/TokenLiner.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/TokenLiner.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TokenLiner.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TokenLiner.cpp$(DependSuffix): TokenLiner.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TokenLiner.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TokenLiner.cpp$(DependSuffix) -MM "TokenLiner.cpp"

$(IntermediateDirectory)/TokenLiner.cpp$(PreprocessSuffix): TokenLiner.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TokenLiner.cpp$(PreprocessSuffix) "TokenLiner.cpp"

$(IntermediateDirectory)/TokenLine.cpp$(ObjectSuffix): TokenLine.cpp $(IntermediateDirectory)/TokenLine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/TokenLine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TokenLine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TokenLine.cpp$(DependSuffix): TokenLine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TokenLine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TokenLine.cpp$(DependSuffix) -MM "TokenLine.cpp"

$(IntermediateDirectory)/TokenLine.cpp$(PreprocessSuffix): TokenLine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TokenLine.cpp$(PreprocessSuffix) "TokenLine.cpp"

$(IntermediateDirectory)/SymbolTable.cpp$(ObjectSuffix): SymbolTable.cpp $(IntermediateDirectory)/SymbolTable.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/SymbolTable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SymbolTable.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SymbolTable.cpp$(DependSuffix): SymbolTable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SymbolTable.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SymbolTable.cpp$(DependSuffix) -MM "SymbolTable.cpp"

$(IntermediateDirectory)/SymbolTable.cpp$(PreprocessSuffix): SymbolTable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SymbolTable.cpp$(PreprocessSuffix) "SymbolTable.cpp"

$(IntermediateDirectory)/Symbol.cpp$(ObjectSuffix): Symbol.cpp $(IntermediateDirectory)/Symbol.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/Symbol.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Symbol.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Symbol.cpp$(DependSuffix): Symbol.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Symbol.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Symbol.cpp$(DependSuffix) -MM "Symbol.cpp"

$(IntermediateDirectory)/Symbol.cpp$(PreprocessSuffix): Symbol.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Symbol.cpp$(PreprocessSuffix) "Symbol.cpp"

$(IntermediateDirectory)/IfNode.cpp$(ObjectSuffix): IfNode.cpp $(IntermediateDirectory)/IfNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/IfNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IfNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IfNode.cpp$(DependSuffix): IfNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IfNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IfNode.cpp$(DependSuffix) -MM "IfNode.cpp"

$(IntermediateDirectory)/IfNode.cpp$(PreprocessSuffix): IfNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IfNode.cpp$(PreprocessSuffix) "IfNode.cpp"

$(IntermediateDirectory)/GDLNode.cpp$(ObjectSuffix): GDLNode.cpp $(IntermediateDirectory)/GDLNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/GDLNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GDLNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GDLNode.cpp$(DependSuffix): GDLNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GDLNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GDLNode.cpp$(DependSuffix) -MM "GDLNode.cpp"

$(IntermediateDirectory)/GDLNode.cpp$(PreprocessSuffix): GDLNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GDLNode.cpp$(PreprocessSuffix) "GDLNode.cpp"

$(IntermediateDirectory)/LegalNode.cpp$(ObjectSuffix): LegalNode.cpp $(IntermediateDirectory)/LegalNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/LegalNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LegalNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LegalNode.cpp$(DependSuffix): LegalNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LegalNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/LegalNode.cpp$(DependSuffix) -MM "LegalNode.cpp"

$(IntermediateDirectory)/LegalNode.cpp$(PreprocessSuffix): LegalNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LegalNode.cpp$(PreprocessSuffix) "LegalNode.cpp"

$(IntermediateDirectory)/TrueNode.cpp$(ObjectSuffix): TrueNode.cpp $(IntermediateDirectory)/TrueNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/TrueNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TrueNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TrueNode.cpp$(DependSuffix): TrueNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TrueNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TrueNode.cpp$(DependSuffix) -MM "TrueNode.cpp"

$(IntermediateDirectory)/TrueNode.cpp$(PreprocessSuffix): TrueNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TrueNode.cpp$(PreprocessSuffix) "TrueNode.cpp"

$(IntermediateDirectory)/NotNode.cpp$(ObjectSuffix): NotNode.cpp $(IntermediateDirectory)/NotNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/NotNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NotNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/NotNode.cpp$(DependSuffix): NotNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/NotNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/NotNode.cpp$(DependSuffix) -MM "NotNode.cpp"

$(IntermediateDirectory)/NotNode.cpp$(PreprocessSuffix): NotNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/NotNode.cpp$(PreprocessSuffix) "NotNode.cpp"

$(IntermediateDirectory)/NextNode.cpp$(ObjectSuffix): NextNode.cpp $(IntermediateDirectory)/NextNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/NextNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NextNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/NextNode.cpp$(DependSuffix): NextNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/NextNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/NextNode.cpp$(DependSuffix) -MM "NextNode.cpp"

$(IntermediateDirectory)/NextNode.cpp$(PreprocessSuffix): NextNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/NextNode.cpp$(PreprocessSuffix) "NextNode.cpp"

$(IntermediateDirectory)/OrNode.cpp$(ObjectSuffix): OrNode.cpp $(IntermediateDirectory)/OrNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/OrNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/OrNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OrNode.cpp$(DependSuffix): OrNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OrNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/OrNode.cpp$(DependSuffix) -MM "OrNode.cpp"

$(IntermediateDirectory)/OrNode.cpp$(PreprocessSuffix): OrNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OrNode.cpp$(PreprocessSuffix) "OrNode.cpp"

$(IntermediateDirectory)/TerminalNode.cpp$(ObjectSuffix): TerminalNode.cpp $(IntermediateDirectory)/TerminalNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/TerminalNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TerminalNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TerminalNode.cpp$(DependSuffix): TerminalNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TerminalNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TerminalNode.cpp$(DependSuffix) -MM "TerminalNode.cpp"

$(IntermediateDirectory)/TerminalNode.cpp$(PreprocessSuffix): TerminalNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TerminalNode.cpp$(PreprocessSuffix) "TerminalNode.cpp"

$(IntermediateDirectory)/GoalNode.cpp$(ObjectSuffix): GoalNode.cpp $(IntermediateDirectory)/GoalNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/GoalNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GoalNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GoalNode.cpp$(DependSuffix): GoalNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GoalNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GoalNode.cpp$(DependSuffix) -MM "GoalNode.cpp"

$(IntermediateDirectory)/GoalNode.cpp$(PreprocessSuffix): GoalNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GoalNode.cpp$(PreprocessSuffix) "GoalNode.cpp"

$(IntermediateDirectory)/RuleNode.cpp$(ObjectSuffix): RuleNode.cpp $(IntermediateDirectory)/RuleNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/RuleNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RuleNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RuleNode.cpp$(DependSuffix): RuleNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RuleNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RuleNode.cpp$(DependSuffix) -MM "RuleNode.cpp"

$(IntermediateDirectory)/RuleNode.cpp$(PreprocessSuffix): RuleNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RuleNode.cpp$(PreprocessSuffix) "RuleNode.cpp"

$(IntermediateDirectory)/PropositionNode.cpp$(ObjectSuffix): PropositionNode.cpp $(IntermediateDirectory)/PropositionNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/PropositionNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PropositionNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PropositionNode.cpp$(DependSuffix): PropositionNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PropositionNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PropositionNode.cpp$(DependSuffix) -MM "PropositionNode.cpp"

$(IntermediateDirectory)/PropositionNode.cpp$(PreprocessSuffix): PropositionNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PropositionNode.cpp$(PreprocessSuffix) "PropositionNode.cpp"

$(IntermediateDirectory)/BaseNode.cpp$(ObjectSuffix): BaseNode.cpp $(IntermediateDirectory)/BaseNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/BaseNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BaseNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BaseNode.cpp$(DependSuffix): BaseNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BaseNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BaseNode.cpp$(DependSuffix) -MM "BaseNode.cpp"

$(IntermediateDirectory)/BaseNode.cpp$(PreprocessSuffix): BaseNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BaseNode.cpp$(PreprocessSuffix) "BaseNode.cpp"

$(IntermediateDirectory)/InputNode.cpp$(ObjectSuffix): InputNode.cpp $(IntermediateDirectory)/InputNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/InputNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/InputNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/InputNode.cpp$(DependSuffix): InputNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/InputNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/InputNode.cpp$(DependSuffix) -MM "InputNode.cpp"

$(IntermediateDirectory)/InputNode.cpp$(PreprocessSuffix): InputNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/InputNode.cpp$(PreprocessSuffix) "InputNode.cpp"

$(IntermediateDirectory)/DistinctNode.cpp$(ObjectSuffix): DistinctNode.cpp $(IntermediateDirectory)/DistinctNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/DistinctNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DistinctNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DistinctNode.cpp$(DependSuffix): DistinctNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DistinctNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DistinctNode.cpp$(DependSuffix) -MM "DistinctNode.cpp"

$(IntermediateDirectory)/DistinctNode.cpp$(PreprocessSuffix): DistinctNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DistinctNode.cpp$(PreprocessSuffix) "DistinctNode.cpp"

$(IntermediateDirectory)/DoesNode.cpp$(ObjectSuffix): DoesNode.cpp $(IntermediateDirectory)/DoesNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/DoesNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DoesNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DoesNode.cpp$(DependSuffix): DoesNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DoesNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DoesNode.cpp$(DependSuffix) -MM "DoesNode.cpp"

$(IntermediateDirectory)/DoesNode.cpp$(PreprocessSuffix): DoesNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DoesNode.cpp$(PreprocessSuffix) "DoesNode.cpp"

$(IntermediateDirectory)/InitNode.cpp$(ObjectSuffix): InitNode.cpp $(IntermediateDirectory)/InitNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/InitNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/InitNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/InitNode.cpp$(DependSuffix): InitNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/InitNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/InitNode.cpp$(DependSuffix) -MM "InitNode.cpp"

$(IntermediateDirectory)/InitNode.cpp$(PreprocessSuffix): InitNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/InitNode.cpp$(PreprocessSuffix) "InitNode.cpp"

$(IntermediateDirectory)/AST.cpp$(ObjectSuffix): AST.cpp $(IntermediateDirectory)/AST.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/AST.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AST.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AST.cpp$(DependSuffix): AST.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AST.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/AST.cpp$(DependSuffix) -MM "AST.cpp"

$(IntermediateDirectory)/AST.cpp$(PreprocessSuffix): AST.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AST.cpp$(PreprocessSuffix) "AST.cpp"

$(IntermediateDirectory)/RelationNode.cpp$(ObjectSuffix): RelationNode.cpp $(IntermediateDirectory)/RelationNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/RelationNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RelationNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RelationNode.cpp$(DependSuffix): RelationNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RelationNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RelationNode.cpp$(DependSuffix) -MM "RelationNode.cpp"

$(IntermediateDirectory)/RelationNode.cpp$(PreprocessSuffix): RelationNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RelationNode.cpp$(PreprocessSuffix) "RelationNode.cpp"

$(IntermediateDirectory)/RoleNode.cpp$(ObjectSuffix): RoleNode.cpp $(IntermediateDirectory)/RoleNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prads/Documents/ProgProjects/My Projects/GGPAgent/RoleNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RoleNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RoleNode.cpp$(DependSuffix): RoleNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RoleNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RoleNode.cpp$(DependSuffix) -MM "RoleNode.cpp"

$(IntermediateDirectory)/RoleNode.cpp$(PreprocessSuffix): RoleNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RoleNode.cpp$(PreprocessSuffix) "RoleNode.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/GGPAgent"


