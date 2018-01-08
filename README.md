libenv - Gestion de l'environnement
------------------------------------

La bibliothèque **libenv** permet la gestion de l'environnement à l'aide de fonctions de recherche, de création et de suppression de variables.

## Utilisation et compilation

*libenv* utilise des fonctions de la [Libft][] et a besoin de son header pour pouvoir être compilé. Il faut fournir au _Makefile_ le chemin vers le dossier le contenant à l'aide de la variable *LIBFT_INC*.

	$> make LIBFT_INC=../libft/includes all

La documentation peut être créée avec la commande suivante :

	$> make doxygen

La documentation est générée grâce à [Doxygen][]. Le _Makefile_ utilise l'alias `doxygen` pour faire appel à l'exécutable, mais si celui-ci n'est pas défini il faut utiliser la commande :

	$> make doxygen DOXYGEN=/CHEMIN/VERS/EXECUTABLE/DE/DOXYGEN

[Libft]: https://github.com/aguerin42/libft.git
[Doxygen]: https://github.com/doxygen/doxygen
