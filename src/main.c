#include "headers/engine.h"




int main(){

    KB* TesteuKB = createEmptyKB();
    Rule* TesteuRule = createEmptyRule();
    FB* fb = createEmptyFB();
    
    Proposition* TesteuProposition = createEmptyProposition();
    Proposition* proop = createEmptyProposition();

    
    TesteuProposition->id = "Helo";
    TesteuProposition->value = true;

    proop->id = "test1";
    proop->value = true;

    addFact(fb,TesteuProposition);
    addFact(fb, proop);

    

    
    Proposition* TesteuConclu = createEmptyProposition();
    TesteuConclu->id = "Conclu";
    TesteuConclu->value = false;
    addConclusion(TesteuRule,TesteuConclu);
    addPremisse(TesteuRule,TesteuProposition);
    addRule(TesteuKB,TesteuRule);
    printf("%s",(headKB(TesteuKB))->head->value->id);

    RuNEnGiNe(TesteuKB,fb);
    
    return EXIT_SUCCESS;
}
