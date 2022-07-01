#ifndef ACTION_H
#define ACTION_H

enum ActionType {
    ACTION_QUIT,
    ACTION_EMPTY,
};

typedef struct Action_Quit Action_Quit;
struct Action_Quit {
    int type;
};

typedef union Action Action;
union Action {
    int type;
    Action_Quit quit;
};

typedef struct ActionQueue ActionQueue;
struct ActionQueue {
    Action action;
    ActionQueue *next;
    ActionQueue *prev;
};

void InitQueue(ActionQueue *queue);
Action ProcessAction(ActionQueue *queue);
void QueueAction(Action *action, ActionQueue *queue);

// Debug
int PrintQueue(ActionQueue *queue);

#endif
