#include "headers/engine.h"




int main(){

    /**Genereating Kb and FB**/
    KB* TesteuKB = createEmptyKB();
    FB* fb = createEmptyFB();

    /**Genereating Rules**/
    Rule* Rule1 = createEmptyRule();
    Rule* Rule2 = createEmptyRule();
    Rule* Rule3 = createEmptyRule();

    /**Generating props**/   
    

    Proposition* Prop1 = createEmptyProposition();
    Prop1->id = "Prop1";
    Prop1->value = false;

    Proposition* Prop2 = createEmptyProposition();
    Prop2->id = "Prop2";
    Prop2->value = false;

    Proposition* Conclu1 = createEmptyProposition();
    Conclu1->id = "Conclu1";
    Conclu1->value = true;

    Proposition* Conclu2 = createEmptyProposition();
    Conclu2->id = "Conclu2";
    Conclu2->value = false;

    /**adding true prop to fb**/
    addFact(fb,Conclu1);

    /**Attributing props to rules' premisse**/
    addPremisse(Rule1,Prop1);

    addPremisse(Rule2,Prop1);
    addPremisse(Rule2,Prop2);

    addPremisse(Rule3,Conclu1);

    /**Attribuing conclusion to rules**/
    addConclusion(Rule1,Prop2);
    
    addConclusion(Rule2,Conclu1);

    addConclusion(Rule3,Conclu2);



    /**Atrributing rules to kb**/
    addRule(TesteuKB,Rule1);
    addRule(TesteuKB,Rule2);
    addRule(TesteuKB,Rule3);

    RuNEnGiNe(TesteuKB,fb);
    printPtrue(fb);
    return EXIT_SUCCESS;
}
 
