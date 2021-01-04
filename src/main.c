#include "headers/interface.h"




int main(){

    /**Genereating Kb and FB**/
    KB* TesteuKB = createEmptyKB();
    FB* fb = createEmptyFB();
    
    FB* PropositionPool = createEmptyFB(); //This grand us an acces to all the propositio an user could want to add

    /**Genereating Rules**/
    //Rule* Rule1 = createEmptyRule();
    Rule* Rule2 = createEmptyRule();
    Rule* Rule3 = createEmptyRule();
	
	//Rule1->name ="yes";
	//addRule(TesteuKB,Rule1);
	TesteuKB = UseraddRule(TesteuKB,"hellO");
    addRule(TesteuKB,Rule2);
    addRule(TesteuKB,Rule3);
    /**Generating props**/   
    

    Proposition* A = createEmptyProposition();
    A->id = "A";
    A->value = true;

    Proposition* B = createEmptyProposition();
    B->id = "B";
    B->value = true;

    Proposition* C = createEmptyProposition();
    C->id = "C";
    C->value = false;
	
	/**
    Proposition* D = createEmptyProposition();
    D->id = "D";
    D->value = false;
    **/
    UseraddProposition(PropositionPool,"D");
    
    Proposition* F = createEmptyProposition();
    F->id = "F";
    F->value = false;


    /**adding true prop to fb**/
    addFact(fb,A);
    addFact(fb,B);


    /**Attributing props to rules' premisse**/
    addPremisse(GetRule(TesteuKB,"hellO"),A);
    addPremisse(GetRule(TesteuKB,"hellO"),B);

    addPremisse(Rule2,C);
    addPremisse(Rule2,GetProposition(PropositionPool,"D"));

    addPremisse(Rule3,B);
    addPremisse(Rule3,C);

    /**Attribuing conclusion to rules**/
    addConclusion(GetRule(TesteuKB,"hellO"),C);
    
    addConclusion(Rule2,F);

    addConclusion(Rule3,GetProposition(PropositionPool,"D"));



    /**Atrributing rules to kb**/
    
	
	
	printKnowledgeBase(TesteuKB);
	printFactBase(fb);
	
    RuNEnGiNe(TesteuKB,fb);
    printFactBase(fb);
    //printPtrue(fb);
    
    printRule(GetRule(TesteuKB,"hellO"));
    return EXIT_SUCCESS;
}
 
