struct					s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
};

int					m(int i, int j)
{
	return (i > j ? i : j);
}

int					count(struct s_node *n, int *max)
{
	if (!n)
		return (0);
	int				right = count(n->right, max);
	int				left = count(n->left, max);
	int				local = m(right, left) + 1;
	int				w = left + right + 1;
	if (*max < w)
		*max = w;
	return (local);
}

int					width_tree(struct s_node *n)
{
	int				max = 1;
	int				local = 0;

	if (!n)
		return (0);
	local = count(n, &max);
	return (max);
}
