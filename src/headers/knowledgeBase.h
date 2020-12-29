#ifndef KNOWLEDGE_BASE
#define KNOWLEDGE_BASE

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
 * @brief Add a new rule at the end of a KB
 */

KB* addRule(KB* kb, Rule* R);

/**
 * @brief Return a pointer to the first rule of a KB
 */

Rule* headKB(KB* kb);

#endif
