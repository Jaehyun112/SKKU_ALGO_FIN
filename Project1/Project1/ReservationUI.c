#include"headerFiles.h"

void ReservationUI() {

	gotoxy(3, 1); printf("[�����ϱ�] - "); textcolor(10); printf("[�����Է�]"); textcolor(15); printf(" - [��μ���] - [Ȯ��] ");
	gotoxy(3, 3); printf("=================================================");
	gotoxy(3, 5); printf("����� : ");
	gotoxy(3, 7); printf("������ : ");
	gotoxy(3, 9); printf("ID     : ");
	gotoxy(3, 11); printf("��  �� : ");
	gotoxy(3, 13); printf("��  �� : ");
	gotoxy(3, 17); printf("=================================================");

	char StartPos[20];
	char DestPos[20]; 
	char id[20]; 
	int Period;
	int budget;
	ReservInput(StartPos, DestPos, id, &Period, &budget);
	// TODO: 
	//node_ptr temp = Dijkstra(StartPos, DestPos);
	// TODO:  HS_MATCH
	//hotel_site_ptr match = HS_MATCH(temp, gp, budget, Period);
	/*
	temp2 = HS_MATCH();
	
	Show(temp2);
	node = (id, temp2)
	RSV_INSERT(node);

	the end
	*/

}

void ReservInput(char *StartPos, char *DestPos, char *id,  int *Period, int *budget) {
	gotoxy(12, 5); fgets(StartPos, 20, stdin); strtok(StartPos, "\n");
	//while (getchar() != '\n');
	gotoxy(12, 7); fgets(DestPos, 20, stdin); strtok(DestPos, "\n");
	//while (getchar() != '\n');
	gotoxy(12, 9); fgets(id, 20, stdin); strtok(id, "\n");
	//while (getchar() != '\n');
	gotoxy(12, 11); scanf("%d", Period);
	while (getchar() != '\n');
	gotoxy(12, 13); scanf("%d", budget);
	while (getchar() != '\n');

	gotoxy(12, 20); printf("%s %s %s %d %d", StartPos, DestPos, id, *Period, *budget);
	while (getchar() != '\n');

}