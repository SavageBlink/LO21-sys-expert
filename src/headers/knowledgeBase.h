#ifndef KNOWLEDGEBASE
#define KNOWLEDGEBASE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rules.h"


/**
 *Define a Knowledge Base which is implemented as a symply linked-list of rules.
 */
typedef struct KBElem{
  Rule*  KBrule;
  struct KBElem * next;
} KBElement;

typedef KBElement * KB;

/**
 * @brief  create an empty KB
 */

KB* createEmptyKB();

/**
 * @param kb - A pointer on the kb you want to add a rule
 * @param R - A pointer on the rule you want to add
 * @brief Add a new rule at the end of a KB
 * @return A pointer on the modified KB
 */

KB* addRule(KB* kb, Rule* R);

/**
 * @param kb - A pointer on the kb you want to get the head from
 * @brief Return a pointer to the first rule of a KB
 * @return The head of the kb
 */

Rule* headKB(KB* kb);




#endif
