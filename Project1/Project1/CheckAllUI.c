#include"headerFiles.h"


int IdxPos, IdyPos;

void	CheckAllUI(RSV_node_ptr head) {
	gotoxy(0, 0); printf(" ");
	// 저장된 모든 예약현황 출력
	gotoxy(2, 0); printf("[모든 예약현황 확인]");
	gotoxy(0, 2); printf("===================================================================================================");
	gotoxy(0, 4); printf("===================================================================================================");
	gotoxy(0, 3); printf("ID"); gotoxy(16, 3); printf("출발"); gotoxy(22, 3); printf("도착"); gotoxy(30, 3); printf("경로");
	
	IdxPos = 0;
	IdyPos = 6;
	RSV_Inorder(head);
	gotoxy(40, 0); printf("메인화면 돌아가려면 enter 입력");
}

void ShowReserveInfo(RSV_node_ptr head) {
	gotoxy(IdxPos, IdyPos); printf("%s : ", head->Key);
}


void RSV_Inorder(RSV_node_ptr head) {
	if (head != Sentinel) {
		RSV_Inorder(head->left);
		ShowReserveInfo(head);
		IdyPos += 5;
		RSV_Inorder(head->right);
	}
}

