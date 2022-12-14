#include "_getline.h"

/**
 * _getline - Return a line in fd
 * @fd: file descriptor
 *
 * Return: line of fd or NULL if error
 */
char *_getline(const int fd)
{
	static reader_t *readers;
	reader_t *rd;
	char *bytes;
	int bytes_read;

	if (fd == -1)
	{
		for (rd = readers; rd; rd = readers)
		{
			readers = rd->next;
			free(rd->buf);
			free(rd);
		}
		return (NULL);
	}

	for (rd = readers; rd; rd = rd->next)
		if (rd->fd == fd)
		{
			if (rd->bytes <= 0)
				rd->bytes = read(fd, rd->buf, READ_SIZE);
			return (find_line(rd));
		}

	bytes = malloc(sizeof(char) * READ_SIZE);
	bytes_read = read(fd, bytes, READ_SIZE);
	if (bytes_read <= 0)
	{
		free(bytes);
		return (NULL);
	}
	rd = malloc(sizeof(reader_t));
	if (rd == NULL)
		return (NULL);
	rd->fd = fd;
	rd->buf = bytes;
	rd->bytes = bytes_read;
	rd->next = readers;
	readers = rd;
	return (find_line(rd));
}

/**
 * find_line - search line in linked list
 * @rd: node of readder_t
 *
 * Return: a String if error NULL
 */
char *find_line(reader_t *rd)
{
	int i, j, line_size = 0, bytes_copied = 0;
	char *line = NULL, *tmp;

	while (rd->bytes > 0)
	{
		if (line_size < bytes_copied + rd->bytes + 1)
		{
			line_size += rd->bytes + 1, tmp = malloc(sizeof(char) * line_size);
			if (tmp == NULL)
			{
				free(line);
				return (NULL);
			}
			memcpy(tmp, line, bytes_copied);
			memset(tmp + bytes_copied, '\0', line_size - bytes_copied);
			free(line), line = tmp;
		}

		for (i = 0; i < rd->bytes; i++)
			if (rd->buf[i] == '\n')
			{
				rd->buf[i++] = '\0', rd->bytes -= i;
				memcpy(line + bytes_copied, rd->buf, i);
				for (j = 0; i < READ_SIZE; j++, i++)
					rd->buf[j] = rd->buf[i];
				for (; j < READ_SIZE; j++)
					rd->buf[j] = '\0';
				return (line);
			}

		memcpy(line + bytes_copied, rd->buf, rd->bytes);
		bytes_copied += rd->bytes;
		rd->bytes = read(rd->fd, rd->buf, READ_SIZE);
	}

	return (line);
}
