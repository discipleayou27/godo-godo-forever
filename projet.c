#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

	//insere un enseignant
	//modifie les informations
	//affiche les informations
	//recherche par le nom
	//recherche par le code id
	//supprime les informations
	//void enregistre les informations
	
//declarationn de la structure de l element
typedef struct enseignant
{
	char		code		[50];
	char		nom			[50];
	char		prenom		[50];
	char		genre		[50];
	char	 nationalite	[50];
	char		grade		[50];
	char		matiere		[50];
	char		classe		[50];
	char		niveau		[50];
	char		contact		[50];
	char		email		[50];
	
	struct enseignant*suivant;
}element;
//declaration de la procedure d'insertion
void insere_Ens( element**liste , 
char*code, char*nom, char*prenom, char*genre, char*nationalite, char*grade, char*matiere, char*classe, char*niveau, char*contact, char*email )
{
	element*nouveau = malloc( sizeof(element) );
	
	strcpy( nouveau->code ,            code    );
	strcpy( nouveau->nom , 	           nom     );
	strcpy( nouveau->prenom , 		   prenom  );
	strcpy( nouveau->genre , 		   genre   );
	strcpy( nouveau->nationalite , nationalite );
	strcpy( nouveau->grade , 		   grade   );
	strcpy( nouveau->matiere ,         matiere );
	strcpy( nouveau->classe ,          classe  );
	strcpy( nouveau->niveau ,          niveau  );
	strcpy( nouveau->contact ,         contact );
	strcpy( nouveau->email ,           email   );
			nouveau->suivant = 		   NULL		;
	if( *liste == NULL )
		*liste = nouveau;
	else
	{
		element*tmp = *liste;
		while( tmp->suivant != NULL )
		{
			tmp = tmp->suivant;
		}
		tmp->suivant = nouveau;
	}
}	
//declaration de la procedure de modification
void modifie_Ens( element*element ,
char*code, char*nom, char*prenom, char*genre, char*nationalite, char*grade, char*matiere, char*classe, char*niveau, char*contact, char*email )
{
	strcpy( element->code ,            code    );
	strcpy( element->nom , 	           nom     );
	strcpy( element->prenom , 		   prenom  );
	strcpy( element->genre , 		   genre   );
	strcpy( element->nationalite , nationalite );
	strcpy( element->grade , 		   grade   );
	strcpy( element->matiere ,         matiere );
	strcpy( element->classe ,          classe  );
	strcpy( element->niveau ,          niveau  );
	strcpy( element->contact ,         contact );
	strcpy( element->email ,           email   );
			element->suivant = 		   NULL		;
	
}
//declaration de la procedure d affichage
void affiche_Ens( element*liste )
{
	element*tmp=liste;
	printf(": \n");
	printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	while( tmp != NULL )
	{
		printf("\t\t\t\t\t\t\t\t\t\t %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s \n",
		tmp->code, 
		tmp->nom, 
		tmp->prenom, 
		tmp->genre, 
		tmp->nationalite, 
		tmp->grade, 
		tmp->matiere, 
		tmp->classe, 
		tmp->niveau, 
		tmp->contact, 
		tmp->email);
		   tmp =tmp->suivant;
	}
}
//declaration de la fonction de recherche
//rechercher par nom
element*recherche_Ens( element*liste , char*nom )
{
	element*tmp = liste ;
	while( tmp != NULL)
	{
		if (strcmp(tmp->nom, nom) == 0) 
		{
            return liste;
        }
        tmp = tmp->suivant;
	}
}
//recherche par code
element*recherche_Ens_code( element*liste , char*code )
{
	element*tmp = liste ;
	while( tmp != NULL)
	{
		if (strcmp(tmp->code, code) == 0) 
		{
            return liste;
        }
        tmp = tmp->suivant;
	}
}
//declaration de la procedure de suppression
//suppression par code
void supprime_Ens_code(element** liste, char*code) 
{
     element* tmp     = *liste;
     element* preced  = NULL;

    while (tmp != NULL) 
	{
        if (strcmp(tmp->code, code) == 0) 
		{
            if (preced == NULL) 
			{
                *liste = tmp->suivant;
            } 
			else 
			{
                preced->suivant = tmp->suivant;
            }
            free(tmp);
            printf("SUPPRESSION DE L ENSEIGNANT EFFECTUEE !\n");
            return;
        }
        preced = tmp;
        tmp = tmp->suivant;
    }

    printf("ENSEIGNANT INVALIDE, AJOUTEZ CONTACT?\n");
}
//declaration de la procedure qui enregistre les donnees dans le fichier
void enregistre_Ens(element* liste, char* nom_Fich) 
{
    FILE*p = fopen(nom_Fich, "w");
    if (p == NULL) 
	{
        return;
    }
	element*tmp = liste ;
    while (tmp != NULL) 
	{
        fprintf(p,"| %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s |",
		tmp->code, 
		tmp->nom, 
		tmp->prenom, 
		tmp->genre, 
		tmp->nationalite, 
		tmp->grade, 
		tmp->matiere, 
		tmp->classe, 
		tmp->niveau, 
		tmp->contact, 
		tmp->email);
           tmp =tmp->suivant;
    }

    fclose(p);
    printf("Enregistrement reussi\n");
}

element*charge(char* nom_Fich) 
{
    FILE* p = fopen(nom_Fich, "r");
    if (p == NULL) 
	{
       
        return NULL;
    }
	
    element*tmp = NULL;
    char		code		[50];
		char		nom			[50];
			char		prenom		[50];
				char		genre		[50];
					char	 nationalite	[50];
						char		grade		[50];
					char		matiere		[50];
				char		classe		[50];
			char		niveau		[50];
		char		contact		[50];
	char		email		[50];

    while (fscanf(p,"| %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s |",
	tmp->code, 
	tmp->nom, 
	tmp->prenom, 
	tmp->genre, 
	tmp->nationalite, 
	tmp->grade, 
	tmp->matiere, 
	tmp->classe, 
	tmp->niveau, 
	tmp->contact, 
	tmp->email ) != EOF) 
	{
        insere_Ens(&tmp, code, nom, prenom, genre, nationalite, grade, matiere, classe, niveau, contact, email);
    }

    fclose(p);
    return tmp;
}
//declaration du programme principal
int main() 
{
    int reponse;
    char		code		[10];
		char		nom			[15];
			char		prenom		[30];
				char		genre		[10];
					char	 nationalite	[10];
						char		grade		[20];
					char		matiere		[30];
				char		classe		[10];
			char		niveau		[30];
		char		contact		[30];
	char		email		[50];
	
	element* donnees_Ens = NULL;
	donnees_Ens = charge("enseignant.xls");
	//void insere_Ens()
	//void modifie_Ens()
	//void affiche_Ens()
	// recherche_Ens()
	// recherche_Ens_code()
	//void supprime_Ens_code()
	//void enregistre_Ens()
	do
	{
		system ("color 3F");
		printf(" \n");
		printf("\t\t\t\t\t\t\t\t	*GESTIONNAIRE DU PERSONNEL DES ENSEIGNANTS DU DEPARTEMENT ITER/UTT LOKO* \n");
		printf("\t\t\t\t\t\t\t\t=========================================================================================\n");
		printf(" \n");
									
								
										printf("\t\t\t\t\t\t\t\t\t\t\t	 MENU DE L' APPLICATION  \n");
							
								
		printf(" \n");										
		printf("\t\t\t\t\t\t\t\t=========================================================================================\n");
		
									printf("\t\t\t\t\t\t\t\t\t\t 1 -> INSERER		UN		ENSEIGNANT     		\n");
									printf("\t\t\t\t\t\t\t\t\t\t 2 -> MODIFIER 		UN  		ENSEIGNANT     		\n");
									printf("\t\t\t\t\t\t\t\t\t\t 3 -> AFFICHER 		UN  		ENSEIGNANT 	 		\n");
									printf("\t\t\t\t\t\t\t\t\t\t 4 -> RECHERCHER 	UN 		ENSEIGNANT   NOM	\n");
									printf("\t\t\t\t\t\t\t\t\t\t 5 -> RECHERCHER	UN 		ENSEIGNANT   CODE   \n");
									printf("\t\t\t\t\t\t\t\t\t\t 6 -> SUPPRIMER		UN 		ENSEIGNANT   CODE   \n");
									printf("\t\t\t\t\t\t\t\t\t\t 7 -> ENREGISTRER	LE		DOSSIER  	    	\n");
									printf("\t\t\t\t\t\t\t\t\t\t 0 -> RETOUR                    				\n");
															
		printf("\t\t\t\t\t\t\t\t=========================================================================================\n");
		printf("\t\t\t\t\t\t\t\t\tBIENVENUE, VEUILLEZ TAPER LE NUMERO POUR EFFECTUER LE SERVICE DE VOTRE CHOIX\n");		
		printf("\t\t\t\t\t\t\t\tRepondre: ");
		scanf("%d",&reponse);
		
		switch (reponse) 
		{
            case 1:
        printf("\t\t\t\t\t\t\t\t=========================================================================================\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\t\tINFORMATIONS PERSONNELLES ET PROFESSIONELLES DE L ENSEIGNANT.\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\tVEUILLEZ RENSEIGNER LA FICHE\n");
            	printf("\t\t\t\t\t\t\t\tCode:");
            	scanf("\t\t\t\t\t\t\t\t%s", code);
                printf("\t\t\t\t\t\t\t\tNom : ");
                scanf("\t\t\t\t\t\t\t\t%s", nom);
                printf("\t\t\t\t\t\t\t\tPrenom : ");
                scanf("\t\t\t\t\t\t\t\t%s", prenom);
                printf("\t\t\t\t\t\t\t\tGenre: ");
                scanf("\t\t\t\t\t\t\t\t%s", genre);
                printf("\t\t\t\t\t\t\t\tNationalite: ");
                scanf("\t\t\t\t\t\t\t\t%s", nationalite);
                printf("\t\t\t\t\t\t\t\tGrade: ");
                scanf("\t\t\t\t\t\t\t\t%s", grade);
                printf("\t\t\t\t\t\t\t\tMatiere: ");
                scanf("\t\t\t\t\t\t\t\t%s", matiere);
                printf("\t\t\t\t\t\t\t\tClasse: ");
                scanf("\t\t\t\t\t\t\t\t%s", classe);
                printf("\t\t\t\t\t\t\t\tNiveau: ");
                scanf("\t\t\t\t\t\t\t\t%s", niveau);
                printf("\t\t\t\t\t\t\t\tContact: ");
                scanf("\t\t\t\t\t\t\t\t%s", contact);
                printf("\t\t\t\t\t\t\t\tEmail: ");
                scanf("\t\t\t\t\t\t\t\t%s", email);
                insere_Ens(&donnees_Ens, code, nom, prenom, genre, nationalite, grade, matiere, classe, niveau, contact, email);
                break;
        printf("\t\t\t\t\t\t\t\t=========================================================================================\n");
            	case 2:
            		printf( "code : " );
                	scanf( "%s", code );
                	element*mod = recherche_Ens_code(donnees_Ens, code);
                if (mod != NULL)
				{
					printf("Code: ");
					scanf("%s", code);
                    printf("Nom: ");
                	scanf("%s", nom);
                	printf("Prenom: ");
                	scanf("%s", prenom);
                	printf("Genre: ");
                	scanf("%s", genre);
                	printf("Nationalite: ");
                	scanf("%s", nationalite);
                	printf("Grade: ");
                	scanf("%s", grade);
                	printf("Matiere: ");
                	scanf("%s", matiere);
                	printf("Classe: ");
                	scanf("%s", classe);
                	printf("Niveau: ");
                	scanf("%s", niveau);
                	printf("Contact: ");
                	scanf("%s", contact);
                	printf("Email: ");
                	scanf("%s", email);
                    modifie_Ens(mod, code, nom, prenom, genre, nationalite, grade, matiere, classe, niveau, contact, email);
                    printf("SUPPRESSION DE L ENSEIGNANT EFFECTUEE\n");
                }
				else
				{
                    printf("ENSEIGNANT INVALIDE, REESSAYER !\n");
                }
                break;
                	case 3:
                		affiche_Ens(donnees_Ens);
                		break;
                			case 4:
                				printf("Nom : ");
                		scanf("%s", nom);
                		element*rech = recherche_Ens(donnees_Ens, nom);
                	if (rech != NULL) 
					{
                    	printf("L ENSEIGNANT REPOND A L IDENTITE DE : | code: %s | nom: %s | prenom: %s | genre: %s | nationalite: % | grade: %s | matiere: %s | classe: %s | niveau: %s | contact: %s | email: %s |\n",
						rech->code,rech->nom,rech->prenom,rech->genre,rech->nationalite,rech->grade,rech->matiere,rech->classe,rech->niveau,rech->contact,rech->email );
                	}
					else
					{
                    	printf("FICHIER INTROUVABLE...\n");
                	}
                	break;
                			case 5:
                				printf("Code : ");
                		scanf("%s", code);
                		element*rechcode = recherche_Ens_code(donnees_Ens, code);
                	if (rech != NULL) 
					{
                    	printf("L ENSEIGNANT REPOND A L IDENTITE DE : | Code: %s |Nom : %s | Prenom: %s | Genre: %s | Nationalite: %s | Grade: %s | Matiere: %s | Classe: %s | Niveau: %s | Contact: %s | Email: %s |\n",
						rechcode->code,rechcode->nom,rechcode->prenom,rechcode->genre,rechcode->nationalite,rechcode->grade,rechcode->matiere,rechcode->classe,rechcode->niveau,rechcode->contact,rechcode->email );
                	}
					else
					{
                    	printf("FICHIER INTROUVABLE...\n");
                	}
                	break;
                		case 6:
               				printf("code : ");
                			scanf("%s", code);
                			supprime_Ens_code(&donnees_Ens, code);
                			break;
                				case 7:
                					enregistre_Ens(donnees_Ens, "enseignant.xls");
                					break;
                						case 0:
                							break;
                							default:
                printf("VEUILLEZ RESSAISIR UN CHIFFRE VALIDE\n");
                break;
        }
    } while (reponse != 0);

    return 0;
}
                		
                		
       	


