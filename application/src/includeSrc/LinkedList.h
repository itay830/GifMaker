#if !defined(LINKEDLIST_TAG) || !defined(LINKEDLIST_TYPE)
#error No type was set for LinkedList.
#endif

#define LINKEDLIST_METHOD_CONCAT(className, methodName) className##methodName
#define LINKEDLIST_METHOD_WRAPPER(className, methodName) LINKEDLIST_CONCAT(className, methodName)
#define LINKEDLIST_METHOD(methodName) LINKEDLIST_METHOD_WRAPPER(LINKEDLIST_TAG, methodName)

#define LINKEDLIST_NODE_CONCAT(tag) tag##_node

typedef struct LINKEDLIST_TAG LINKEDLIST_TAG;


struct LINKEDLIST_TAG {
  LINKEDLIST_TYPE *head;

};

#undef LINKEDLIST_TAG
#undef LINKEDLIST_TYPE
#undef LINKEDLIST_METHOD_CONCAT
#undef LINKEDLIST_METHOD
#undef LINKEDLIST_METHOD_WRAPPER