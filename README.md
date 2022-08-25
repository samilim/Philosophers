# Philosophers
Ce projet est une introduction au threading et aux processus, et sur comment travailler sur le même espace mémoire.

## Arguments du project
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

______

# Notions

## Multi threading
Chaque philosopher doit être représenté par un thread.
pthread_detach permet de "détacher" un thread du thread principal. Un thread détaché n'est plus joinable. AUssi, ils clear automatiquement leurs ressources.

## Fonctions

- pthread join 
- pthread detach 

### Difference between thread and process
PLusieurs threads peuvent être contenus dans un seul process, l'inverse est impossible.
Avec les process, on duplique les données lors de la creation de child process. On obtient alors des "variables" individuelles. 
Avec les threads, les données utilisent la même mémoire, ce qui veut dire que tous les threadds peuvent acceder à toutes les variables et ne sont pas indépendants entre eux.

### Race conditions
Quand une variable est modifiée simultanément dans plusieurs threads, cela peut créer un conflit qu'on appelle "Race condition". Pour éviter le problème nous utilisons alors des "mutex".

### Mutex
Un mutex permet de protéger un espace mémoire en "bloquant" une section de la mémoire, jusqu'a ce que cet espace soit débloqué, ce qui veut dire que les autres thread attendront que la ressource soit débloquée pour continuer.
Concrètement dans ce projet, les mutex vont permettre d'empêcher les philosophes de dupliquer les fourchettes.

### Deadlocks
Un deadlock survient quand plusieurs thread essaient de locker un même mutex en même temps.

### Usleep
Version microseconde de sleep. (1 microseconde = 0,001 milliseconde)

### Semaphores
A voir plus tard pour les bonus (voir codevault)
______

## WARNINGS
Libft non autorisée ! Ne pas oublier de déplacer les fonctions utlisées hors du dossier libft (voir sujet pour connaitre les fonctions autorisées).

???
COntinuer la routine une fois le nb de repas max atteint ?
Verif mort avant join ou creer un thread parallèle ?

## Ressources intéressantes
chaine ytb CodeVault
