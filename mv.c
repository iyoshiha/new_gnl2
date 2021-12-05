void move_save_to_line(t_txt *txt, char **save)
{
	int i;
	int len_after_breakline;
	char *old_save;

	i = 0;
	len_after_breakline = txt->save_len - txt->index_of_break;
	if (txt->index_of_break == GNL_BREAK_NOT_FOUND)
		txt->line = (char *)malloc(txt->save_len + END_STR);
	else
		txt->line = (char *)malloc(NEXT_INDEX_OF txt->index_of_break + END_STR); // 1 for null, 1 for conv index to len;
	while ((*save)[i] != '\0')
	{
		txt->line[i] = (*save)[i];
		i = NEXT_INDEX_OF i;
		if ((*save)[i OF_PREVIOUS] == '\n') // after put \n in line then move but we didnt exam so -1
			break;
	}
	txt->line[i] = '\0';
	if ((txt->len_read == END_OF_FILE) && (txt->index_of_break == GNL_BREAK_NOT_FOUND)) //last line // find_break_line's return value can be flag
	{
		free(*save);
		*save = NULL;
		return;
	}
	old_save = *save;
	*save = (char *)malloc((len_after_breakline));
	ft_strlcat(*save, (old_save + NEXT_INDEX_OF txt->index_of_break), len_after_breakline);
	free(old_save);
}
