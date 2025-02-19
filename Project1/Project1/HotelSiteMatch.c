#include"headerFiles.h"

hotel_site_ptr HS_MATCH(node_ptr node, graph_ptr gp, int budget, int period) { //경로노드를 받으면 매치
	hotel_site_ptr head;
	hotel_site_ptr ptr;
	node_ptr nptr = node;
	int sitenum = 0;
	head = HS_SATISFACTION(nptr, gp);
	head->Budget = budget; //head의 예산 총예산
	head->next = NULL;
	ptr = head;
	nptr = nptr->next;
	sitenum++;


	while (nptr != NULL) {
		ptr->next = HS_SATISFACTION(nptr, gp);
		ptr->next->Budget = ptr->Budget - 20 * nptr->Weight; //호텔사이트의 예산 계속 차감 !!Weight(1~100) *20
		ptr = ptr->next;
		nptr = nptr->next;
		sitenum++; //노드 붙일때마다 site 수를 증가
		if (ptr->Budget < 0) return NULL; //budget 0보다 작으면 NULL;
	}

	head = HS_DAY(head, period, sitenum);

	return head; //head가 NULL이면 없다는 것
}//경로에 최저가 호텔 놓는다.->만족도로 날짜 더해

hotel_site_ptr HS_SATISFACTION(node_ptr node, graph_ptr gp) { //도시 이름과 평점을 받으면, 만족도를 계산해서 제일 좋은 호텔 정보를 담은 노드를 리턴
	hotel_site_ptr hotelsite = (hotel_site_ptr)malloc(sizeof(HotelSite));
	int satisfaction;
	int pricesatis;
	int prefersatis;
	int citynum = node->CityNum;
	int preference = gp->CityInfo[citynum].perference;
	HT_RBnode_ptr Hotel = HT_TREE_MIN(getAllHotelinfo(gp, citynum));
	int price = Hotel->Key;

	pricesatis = 3000 - 3 * Hotel->Key; //가격 1~1000일때
	prefersatis = preference * 400; //평점 0~5
	satisfaction = pricesatis + prefersatis;

	hotelsite->CityNum = citynum;
	hotelsite->Preference = preference;
	hotelsite->Hotel = Hotel->Hotel_Num;
	hotelsite->Price = Hotel->Key;
	hotelsite->Satisfaction = satisfaction;
	hotelsite->Day = 1; //시작은 최소 하루 부터
	hotelsite->next = NULL;

	return hotelsite;

}

hotel_site_ptr HS_DAY(hotel_site_ptr head, int period, int sitenum) {  //도시의 만족도에 따라 기간 배분 (하루 묵을때마다 만족도-500) budget -일 때 고려, budget재계산
	hotel_site_ptr select_day; //날짜를 더할 호텔
	int minusbudget = 0;
	int dayleft = period - sitenum;
	int i;
	int maxsatis;
	int budgetleft = -1;
	int minprice = 2000;
	int maxprice = -1;
	int satis_day; //만족도 날짜 환산
	hotel_site_ptr ptr = head;
	if (ptr == NULL) return NULL; //ptr NULL인지 확인



	if (dayleft < 0) { //경로수가 묵는 날보다 클 때
		return NULL;
	}
	else if (dayleft == 0) { //경로수가 묵는 날과 같을 때
		return head;
	}
	else { //경로수보다 묵는 날이 클때

		while (ptr != NULL) {//price 최저가, 남은예산
			if (ptr->Price < minprice) minprice = ptr->Price;
			if (ptr->Price > maxprice) maxprice = ptr->Price;
			budgetleft = ptr->Budget; //마지막노드가 남은 노드
			ptr = ptr->next;
		}
		ptr = head;


		if (ptr != NULL)

			for (i = 0; i < dayleft; i++) {//만족도가 작더라도 budget만족 시키게
				if (budgetleft < minprice*(dayleft - i)) return NULL;
				if (budgetleft > minprice*(dayleft - i) && budgetleft < minprice*(dayleft - (i + 1)) + maxprice) {
					ptr = head;
					while (ptr != NULL) {
						if (ptr->Budget == minprice)
							ptr->Day += (dayleft - i);
					}
					break;
				}


				ptr = head;
				maxsatis = -10000; //초기값
				while (ptr != NULL) {
					satis_day = ptr->Satisfaction - (500 * (ptr->Day - 1)); //날짜 환산
					if (maxsatis < satis_day) {
						maxsatis = satis_day;
						select_day = ptr;
					}
					ptr = ptr->next;
				}
				select_day->Day++;

			}

	}
	ptr = head;
	while (ptr != NULL) {
		minusbudget = minusbudget + ptr->Price*(ptr->Day);
		ptr->Budget = ptr->Budget - minusbudget;
		ptr = ptr->next;
	}	//budget 재계산 budget -일 때 return NULL;

	return head;
}