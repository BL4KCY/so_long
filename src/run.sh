#!bin/bash
cc -fsanitize=leak prase_map.c ../libft/libft.a -I../includes -I../libft/includes && clear && ./a.out /nfs/homes/melfersi/Cursus/mlx/maps/valid/map-square.ber
sleep 1
bash run.sh
