#include "headers/engine.h"




int main(){

    KB* TesteuKB = createEmptyKB();
    Rule* TesteuRule = createEmptyRule();
    FB* fb = createEmptyFB();
    
    Proposition* TesteuProposition = createEmptyProposition();
    Proposition* proop = createEmptyProposition();

    
    TesteuProposition->id = "Helo";
    TesteuProposition->value = false;

    proop->id = "test1";
    proop->value = true;

    //addFact(fb,TesteuProposition);
    addFact(fb, proop);

    

    
    Proposition* TesteuConclu = createEmptyProposition();
    TesteuConclu->id = "Conclu";
    TesteuConclu->value = false;
    addConclusion(TesteuRule,TesteuConclu);
    addPremisse(TesteuRule,TesteuProposition);
    addPremisse(TesteuRule,proop);
    addRule(TesteuKB,TesteuRule);

    RuNEnGiNe(TesteuKB,fb);
    printPtrue(fb);
    return EXIT_SUCCESS;
}
