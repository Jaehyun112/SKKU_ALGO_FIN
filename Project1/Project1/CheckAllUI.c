#include"headerFiles.h"


int IdxPos, IdyPos;

void	CheckAllUI(RSV_node_ptr head) {
	gotoxy(0, 0); printf(" ");
	// ����� ��� ������Ȳ ���
	gotoxy(2, 0); printf("[��� ������Ȳ Ȯ��]");
	gotoxy(0, 2); printf("===================================================================================================");
	gotoxy(0, 4); printf("===================================================================================================");
	gotoxy(0, 3); printf("ID"); gotoxy(16, 3); printf("���"); gotoxy(22, 3); printf("����"); gotoxy(30, 3); printf("���");
	
	IdxPos = 0;
	IdyPos = 6;
	RSV_Inorder(head);
	gotoxy(40, 0); printf("����ȭ�� ���ư����� enter �Է�");
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

