#include "headers/knowledgeBase.h" 



int main(){

    KB* TesteuKB = createEmptyKB();
    Rule* TesteuRule = createEmptyRule();

    Proposition* TesteuProposition = createEmptyProposition();
    TesteuProposition->id = "Helo";
    TesteuProposition->value = false;

    Proposition* TesteuConclu = createEmptyProposition();
    TesteuConclu->id = "Conclu";
    TesteuConclu->value = false;
    addConclusion(TesteuRule,TesteuConclu);
    addPremisse(TesteuRule,TesteuProposition);
    addRule(TesteuKB,TesteuRule);
    printf("%s",(headKB(TesteuKB))->head->value->id);

    return EXIT_SUCCESS;
}