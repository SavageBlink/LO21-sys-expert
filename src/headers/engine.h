/**
 * @file engine.h
 * @author Guillaume/Hendercraft Driss/SavageBlink
 * @date 30 december 2020
 * @brief Header file of the main inferrence engine, it also defines a linked-list of facts (true propo
 * sitions)
 */

#ifndef ENGINE
#define ENGINE
#include "knowledgeBase.h"

typedef struct factElem{
  Proposition* value;
  struct factElem * next;
}factElement;

typedef factElement * FB;


/**
 * @param NONE
 * @return Return a pointer to an empty base of facts
 * @brief Create an empty linked-list of facts
 */
FB* createEmptyFB();

/**
 * @param fb - Pointer to a base of facts you want to modify
 * @param P - Pointer to a proposition you want to add 
 * @return Return a modified base of facts
 * @brief Add facts to a List of facts
 */

FB* addFact(FB* fb,Proposition* P);

/**
 * @param fb - pointer to a fact base
 * @param id - string which identify the fact you want to delete
 * @return Return a modified base of facts
 * @brief Delete a fact from a fact base
 */
FB* deleteFact(FB* fb, char * id);

/**
 * @param fb - pointer to a fact base
 * @brief print the Id of all the Proposition 
 */
void printPtrue(FB* fb);
/**
 * @param kb - Pointer to a knowledge base
 * @param fb - Pointer to a fact base
 * @return Return all true propositions from given rules and facts
 * @brief eNgInE
 */
FB* RuNEnGiNe(KB* kb, FB* fb);


#endif
