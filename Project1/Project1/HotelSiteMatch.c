#include"headerFiles.h"

hotel_site_ptr HS_MATCH(hotel_site_ptr head, node_ptr node, graph_ptr gp, int budget) { //��γ�带 ������ ��ġ
	hotel_site_ptr ptr = head; //head���� �� ���길 ����ִ�.
	int sitenum = 0;

	head->Budget = budget;
	while (node != NULL) {
		ptr->next = HS_SATISFACTION(node, gp);
		ptr->next->Budget = ptr->Budget - 100 * node->Weight - ptr->next->Price; //ȣ�ڻ���Ʈ�� ���� ��� ���� !!Weight ����ġ ����
		ptr = ptr->next;
		node = node->next;
		sitenum++; //��� ���϶����� site ���� ����
		if (ptr->Budget < 0) return NULL; //budget 0���� ������ NULL;
	}


}//��ο� ������ ȣ�� ���´�.->�������� ��¥ ����

hotel_site_ptr HS_SATISFACTION(node_ptr node, graph_ptr gp) { //���� �̸��� ������ ������, �������� ����ؼ� ���� ���� ȣ�� ������ ���� ��带 ����
	hotel_site_ptr hotelsite = (hotel_site_ptr)malloc(sizeof(HotelSite));
	int satisfaction;
	int pricesatis;
	int prefersatis;
	int citynum = node->CityNum;
	int preference = gp->CityInfo[citynum].perference;
	HT_RBnode_ptr Hotel = HT_TREE_MIN(getAllHotelinfo(gp, citynum));
	int price = Hotel->Key;

	pricesatis = 3000 - 3 * Hotel->Key; //���� 1~1000�϶�
	prefersatis = preference * 4; //���� 0~5
	satisfaction = pricesatis + prefersatis;

	hotelsite->CityNum = citynum;
	hotelsite->Hotel = Hotel->Hotel_Num;
	hotelsite->Price = Hotel->Key;
	hotelsite->Satisfaction = satisfaction;
	hotelsite->Day = 1; //������ �ּ� �Ϸ� ����

	return hotelsite;

}

hotel_site_ptr HS_DAY(hotel_site_ptr head, int period, int sitenum) {  //������ �������� ���� �Ⱓ ��� (�Ϸ� ���������� ������-500) budget -�� �� ���, budget����
	int dayleft = period - sitenum;
	int i;
	int maxsatis;
	int budgetleft = -1;
	int minprice = 2000;
	int maxprice = -1;
	hotel_site_ptr ptr = head->next;
	if (ptr == NULL) return NULL; //ptr NULL���� Ȯ��





	if (dayleft < 0) { //��μ��� ���� ������ Ŭ ��
		return NULL;
	}
	else if (dayleft == 0) { //��μ��� ���� ���� ���� ��
		return head;
	}
	else { //��μ����� ���� ���� Ŭ��

		while (ptr != NULL) {//price ������, ��������
			if (ptr->Price < minprice) minprice = ptr->Price;
			if (ptr->Price > maxprice) maxprice = ptr->Price;
			budgetleft = ptr->Budget; //��������尡 ���� ���
			ptr = ptr->next;
		}
		ptr = head->next;


		if (ptr != NULL)

			for (i = 0; i < dayleft; i++) {//�������� �۴��� budget���� ��Ű��
				if (budgetleft > minprice*(dayleft - i) && budgetleft < minprice*(dayleft - (i + 1)) + maxprice) {

				}


				ptr = head->next;
				maxsatis = -10000;
				while (ptr != NULL) {
					if (maxsatis < ptr->Satisfaction) maxsatis = ptr->Satisfaction;
					ptr = ptr->next;
				}

				ptr = head->next;
				while (ptr != NULL) {
					if (maxsatis == ptr->Satisfaction) {
						ptr->Day++;
						budgetleft -= ptr->Price;
						break;
					}
					ptr = ptr->next;
				}

			}

	}
	//budget ���� budget -�� �� return NULL;


}