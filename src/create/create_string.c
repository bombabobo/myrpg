#include "../../include/my.h"

void create_string(sfText *text, cc_t *string, ui_t size)
{
    sfText_setString(text, string);
    sfText_setCharacterSize(text, size);
}
