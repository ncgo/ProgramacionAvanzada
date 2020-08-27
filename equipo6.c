#include <stdio.h>
#include <string.h>
#include <regex.h>

struct Asset {
    char name[64];
    char last_name[64];
    char id[13];
};

struct Agent {
    char name[64];
    char last_name[64];
	int age;
    char gender;
	struct Asset *asset[10];
    char mission[12];
    int numAssets;
};

//Globales
struct Agent agents[10];
struct Asset assets[100];
char mission[64][12];

//Registers
void registerAgent(){
    
}

void getAgents(int currAgents){
    for(int i = 0; i < currAgents; i++){
        printf("%d - %s %s \n", i+1, agents[i].name, agents[i].last_name);
    }
}

void getAgentInfo(int num, int currAgents){
    if(num <= currAgents && num > 0){
        num--;
        printf("Agent Complete Name: %s %s \n", agents[num].name, agents[num].last_name);
        printf("Agent age: %d \n", agents[num].age);
        printf("Agent gender: %c \n", agents[num].gender);
        //implementar assets
        printf("Agent Current mission: %s\n", agents[num].mission);
    }else
    {
        printf("Invalid agent number");
    }
    
}

void registerMission(char mis[12]){
    
}

//Check if mission exists
void checkMission(){
    //if mission in mission 
}

int checkAssetID(char id[13]){
    regex_t regex;
    int validID, valCompi;
    valCompi = regcomp(&regex, "^[A-Za-z]{4}[0-9]{9}$", REG_ICASE | REG_EXTENDED );
    validID = regexec(&regex, id, 0,NULL, 0);
    if(validID == 0){
        return 1;
    }
    else if(validID == REG_NOMATCH)
    {
        printf("Invalid ID, pattern is aaaa012345678 \n");
        return 0;
    }
    else 
        return 0;
}



int main() {
    regex_t regex;
    int return_value;
	int num;
    int iAsset = 0;
    int iAgent = 0;
	int iMission = 0;
	
	do {
        printf("---------------\n");
        printf( "Select your task:\n 1. Add a new agent \n 2. Add a new mission \n 3. Add a new asset \n 4.Get Agents \n 5.Get Agent Specific Info  \n 6. Quit \n");
        scanf("%d", &num);
        switch (num) {
            case 1:{
                // Registrar agente
                struct Agent agent;
                char a_id[64];
                char mission[12];
                int noAsset;
                
                printf("You have chosen to add a new agent. \n Please enter the following information:\n");
                printf("First Name:\n");
                scanf("%s", agent.name);


                printf("Last Name:\n");
                scanf("%s", agent.last_name);
                
                printf("Age:\n");
                scanf("%d", &agent.age);
                
                printf("Gender (M/F):\n");
                scanf(" %c", &agent.gender);
                
                printf("How many assets will you be adding?\n");
                scanf("%d", &noAsset);
                
                /* Implementar el registro de assets
                for (short int i = 0; i < noAsset; i++) {
                    printf("Please enter the AssetID\n");
                    scanf("%s", a_id);
                    registerAsset(a_id);
                }*/
        
                printf("Enter agents current mission: \n");
                scanf("%s", agent.mission);
                //checkMission();
                //registerMission(mission);
                agents[iAgent] = agent;
                iAgent++;
            }
                break;

            case 2:{
                // Registrar mision
                char new_mission[12];
                printf("You have selected to register a mission. Please enter the ID mission:");
                scanf("%s", new_mission);
                // agregar la misión al arreglo de arreglos
                registerMission(new_mission);
            }
                break;
            
            case 3:{
                // Pedir datos de asset
                struct Asset asset;
                int flag = 0;//bandera id correcto de asset
                
                printf("Name: ");
                scanf("%s", asset.name);
                
                printf("Last name: ");
                scanf("%s", asset.last_name);
                
                while(flag != 1){
                    printf("Asset ID: ");
                    scanf("%s", asset.id);
                    flag = checkAssetID(asset.id);
                }
                
                //registro
                assets[iAsset] = asset;
                iAsset++;
                printf("Asset registered. \n");
            }
                break;
            case 4:{ //Obtener los agentes y su numero asociado
                printf("Current agents: \n");
                getAgents(iAgent);
                printf("Request completed \n");
                break;
            }
            case 5:{ //Info detallada de un agente
                int agent_num;
                printf("Enter agente number: \n");
                scanf("%d", &agent_num);
                getAgentInfo(agent_num, iAgent);
                break;
            }
            case 6:
                //Salir del programa
                break;
            default:
                printf("Invalid option. Try again.");
                break;
        }
        
    } while(num!=6);
    printf( "Thank you for using this application. Good luck on your mission. The Secretary is counting on you. \n" );
    return 0;
}