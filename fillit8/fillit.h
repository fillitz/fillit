/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:45:51 by kcharlet          #+#    #+#             */
/*   Updated: 2019/11/22 17:45:53 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"

# define USAGE "usage:\t./fillit input_file\n"

typedef struct	s_tet {
	int			x[4];
	int			y[4];
	char		c;
}				t_tet;

typedef struct	s_map {
	char		**array;
	int			xmax;
	int			ymax;
}				t_map;

typedef struct	s_char {
	int			hash;
	int			dot;
	int			newline;
}				t_char;

char			*extraction_of_tetrimino(char *filename);
t_tet			**ft_read_all_tetrimino(char *tetrimino);
void			ft_free_map(t_map *map);
char			**ft_new_array(int x, int y);
int				ft_load_tetrimino(t_tet *t, t_map *map, int x, int y);
void			ft_remove_tetrimino(t_tet *t, t_map *map, int x, int y);
t_map			*ft_starting_map(char *tetrimino);
t_map			*ft_resize_map(t_map *old_map);
void			ft_print_array(char **array);
void			ft_print_tetrimino(t_tet *tetrimino);
char			**ft_fillit(char *tetrimino);
int				check_colrow(char *str, int tet);
int				main_check(char *str);
int				check_hash(char *str);
void			ft_exit(void);

#endif
