#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * compare_cards - Compare two cards for qsort
 * @a: Pointer to the first card pointer
 * @b: Pointer to the second card pointer
 *
 * Return: Integer value indicating the comparison result
 */
int compare_cards(const void *a, const void *b)
{
    const card_t *card_a = *((const card_t **)a);
    const card_t *card_b = *((const card_t **)b);

    if (card_a->kind != card_b->kind)
        return card_a->kind - card_b->kind;

    return strcmp(card_a->value, card_b->value);
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: Pointer to a pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    int card_count = 0;
    deck_node_t *current = *deck;

    while (current != NULL)
    {
        card_count++;
        current = current->next;
    }

    const card_t *cards[card_count];
    current = *deck;
    for (int i = 0; i < card_count; i++)
    {
        cards[i] = current->card;
        current = current->next;
    }

    qsort(cards, card_count, sizeof(card_t *), compare_cards);

    *deck = NULL;
    for (int i = card_count - 1; i >= 0; i--)
    {
        deck_node_t *new_node = (deck_node_t *)malloc(sizeof(deck_node_t));
        if (!new_node)
            return;
        new_node->card = cards[i];
        new_node->next = *deck;
        if (*deck)
            (*deck)->prev = new_node;
        new_node->prev = NULL;
        *deck = new_node;
    }
}

