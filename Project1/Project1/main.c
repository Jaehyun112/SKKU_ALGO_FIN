#include"headerFiles.h"

/*
 * Created by SKKU_ALGO Team5 on 2018.11.18
*/

int main(void) {
	// INIT ======================================
	//HT_RBnode_ptr head = HT_MakeRBT();
	graph_ptr gp;
	HT_MakeSentinel();
	MakeSentinel();
	GraphInit(&gp);
	RSV_node_ptr ReserveHead = RSV_MakeRBT();
	// Test ===================

	int fromV = 10;
	int toV = 17;
	//printf(" [%d] - [%d] \n", fromV, toV);
	//Dijkstra(gp, fromV, toV);
	//ShowGraph(gp);
	//puts("===================== ");
	// ShowHotelInfo(gp, 2);
	char id[30] = "cbcd123";
	RSV_RB_INSERT(&ReserveHead, id);
	strcpy(id, "aekeke");
	RSV_RB_INSERT(&ReserveHead, id);
	strcpy(id, "dcerf1123");
	RSV_RB_INSERT(&ReserveHead, id);
	strcpy(id, "awefac2");
	RSV_RB_INSERT(&ReserveHead, id);
	strcpy(id, "bbaba");
	RSV_RB_INSERT(&ReserveHead, id);

	//InorderTest(ReserveHead);
	//system("pause");
	//=====================================
	
	int nKey, MoveBar;
	ScreenInit();
	init(&MoveBar); 
	
	while (1) {
		switch (Stage) {
		case RESERVATION:
			ScreenRelease(); ScreenClearFunc();
			ReservationUI();
			Stage = MAIN;
			ScreenInit();
			break;
		case CHECK:
			ScreenRelease(); ScreenClearFunc();
			// TODO : CheckAndCancelUI();
			Stage = MAIN;
			ScreenInit();
			break;
		case CANCEL:
			ScreenRelease(); ScreenClearFunc();
			// TODO or Not : ChangeUI();
			Stage = MAIN;
			ScreenInit(); 
			break;
		case CHECKALL:
			ScreenRelease(); ScreenClearFunc();
			CheckAllUI(ReserveHead);
			Stage = MAIN;
			ScreenInit(); // Screen restart
			while (getchar() != '\n');
			break;
		default: // MAIN ȭ��
			if (_kbhit()) {
				nKey = _getch();
				if (nKey == 13) { // Mainȭ�鿡�� enter �Է½� MoveBar�� ����Ű�� �ִ� Stage�� ����
					Stage = MoveBar - 11;
				}
				if (nKey == 224) { // Mainȭ�鿡�� ����Ű�� ���� MoveBar�� �����̴� ����
					nKey = _getch();
					switch (nKey) {
					case UP:
						MoveBar--;
						break;
					case DOWN:
						MoveBar++;
						break;
					case LEFT: // �ڷΰ���
						Stage = MAIN;
						break;
					case RIGHT:
						break;
					}
				}
			}
			break;
		}
		Render(&MoveBar);  // ȭ�����
	}
	ScreenRelease();
	return 0;
}


