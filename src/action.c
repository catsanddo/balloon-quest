#include "action.h"
#include <stdio.h>
#include <stdlib.h>

// The head of the queue is a dummy so that we have clear and direct access
// to the next and prev *pointers* (eg no pointers to pointers needed)
void InitQueue(ActionQueue *queue)
{
    if (queue) {
        queue->action.type = ACTION_EMPTY;
        queue->next = queue;
        queue->prev = queue;
    }
}

Action ProcessAction(ActionQueue *queue)
{
    Action action;
    ActionQueue *old_head;

    if (queue->next->action.type == ACTION_EMPTY) {
        return (Action) { .type = ACTION_EMPTY };
    }

    action = queue->next->action;

    old_head = queue->next;
    queue->next = queue->next->next;
    queue->next->prev = queue;
    free(old_head);

    return action;
}

void QueueAction(Action *action, ActionQueue *queue)
{
    ActionQueue *new;

    new = malloc(sizeof(ActionQueue));
    new->action = *action;
    new->next = queue;
    new->prev = queue->prev;

    queue->prev->next = new;
    queue->prev = new;
}

int PrintQueue(ActionQueue *queue)
{
    int valid = 1;
    ActionQueue *current = queue;

    printf("Head:\n");
    do {
        int old_valid = valid;
        valid = current == current->prev->next &&
            current == current->next->prev;
        valid &= old_valid;

        printf("(%p)->type = %d\n", current, current->action.type);
        printf("(%p)->prev = %p\n", current, current->prev);
        printf("(%p)->next = %p\n\n", current, current->next);

        current = current->next;
    } while (current->action.type != ACTION_EMPTY);
    printf("%s\n", valid ? "Valid!" : "Not valid!");

    return valid;
}
