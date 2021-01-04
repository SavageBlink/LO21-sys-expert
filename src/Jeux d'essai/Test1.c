#include "headers/engine.h"




int main(){

    /**Genereating Kb and FB**/
    KB* TesteuKB = createEmptyKB();
    FB* fb = createEmptyFB();

    /**Genereating Rules**/
    Rule* Rule1 = createEmptyRule();

    /**Generating props**/   
    

    Proposition* Prop1 = createEmptyProposition();
    Prop1->id = "A";
    Prop1->value = true;

    Proposition* Prop2 = createEmptyProposition();
    Prop2->id = "B";
    Prop2->value = false;

    Proposition* Conclu1 = createEmptyProposition();
    Conclu1->id = "C";
    Conclu1->value = false;

    /**adding true prop to fb**/
    addFact(fb,Prop1);
    //addFact(fb,Prop2);

    /**Attributing props to rules' premisse**/
    addPremisse(Rule1,Prop1);
    addPremisse(Rule1,Prop2);

    /**Attribuing conclusion to rules**/
    //addConclusion(Rule1,Conclu1);
    

    /**Atrributing rules to kb**/
    addRule(TesteuKB,Rule1);


    RuNEnGiNe(TesteuKB,fb);
    printPtrue(fb);
    return EXIT_SUCCESS;
}
