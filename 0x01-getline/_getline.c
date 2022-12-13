#include "_getline.h"


/*lines_t *add_line(lines_t **head, const char *str)
{
	lines_t *new;
	lines_t *tmp = *head;

	new = (lines_t *)malloc(sizeof(lines_t));
	if (new == NULL)
		return (NULL);

	new->len = _strlen((char *)str);
	new->str = strdup(str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = new;

	return (new);
}*/

char *_getline(const int fd)
{
    int size_buf = READ_SIZE;
    int size_tmp = 0;
    char *buffer;
    char tmp[READ_SIZE];

    buffer = (char *)malloc(sizeof(char) * READ_SIZE);
    if (!buffer)
        return (NULL);

    memset(buffer, '\0', READ_SIZE);

    while ((size_tmp = read(fd, tmp, READ_SIZE)) > 0)
    {
        //printf("size_tmp = %d\n", size_tmp);
        //printf("size_buf = %d\n", size_buf);
        if (size_tmp == READ_SIZE)
        {
            size_buf += READ_SIZE;
            buffer = (char *)realloc(buffer, size_buf);
        }
        strcat(buffer, tmp);
        memset(tmp, '\0', READ_SIZE);
    }

    return (buffer);
}