# Philosophers
Ce projet est une introduction au threading et aux processus, et sur comment travailler sur le même espace mémoire.

## Arguments
- nombre de philosophers (correspondant aussi au nb de fourchettes)
- time to die (en ms) : Si un philo n'a pas commencé à manger [time to die] après le début de son précédent repas ou depuis le début de la simulation, il meurt.
- time to eat (en ms) : Le temps pris par un philo pour manger. Le philo doit garder ses deux fourchettes pendant ce temps.
- time to sleep (en ms) : Le temps passé à dormir
- (optionnel) nb de fois chaque philo doit manger : la simulation prend fin quand tous les philos on mangé autant de fois que cette variable indique. Si cet argument n'est pas spécifié, la simulation prend fin à la mort d'un philo.

## Règles communes aux parties obligatoires et bonus
- Pas de variable globale.
- des logs sont à implémenter (voir sujet)
- Il ne doit pas y avoir + de 10ms entre la mort d'un philo et l'affichage du message annonçant sa mort.
- Les philos ne doivent pas mourrir.

## Mutex
Permet de protéger un espace mémoire afin d'empêcher les philosophes de dupliquer les fourchettes.

## Semaphores

## Multi threading
Chaque philosopher doit être représenté par un thread.

## Multi processing

# WARNINGS
Libft non autorisée ! Ne pas oublier de déplacer les fonctions utlisées hors du dossier libft (voir sujet pour connaitre les fonctions autorisées).