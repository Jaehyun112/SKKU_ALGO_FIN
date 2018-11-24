#pragma once

#include"Graph.h"

typedef struct HOTEL_SITE_MATCH *hotel_site_ptr;
typedef struct HOTEL_SITE_MATCH {
	int CityNum;      //HS_SATIS���� ä��κ�
	int Hotel;         //HS_SATIS���� ä��κ�
	int Satisfaction;   //HS_SATIS���� ä��κ�
	int Price;          //HS_SATIS���� ä��κ�
	int Day;         //HS_DAY
	int Budget;         //HS_DAY
	hotel_site_ptr next;
}HotelSite;

hotel_site_ptr HS_MATCH(hotel_site_ptr head, node_ptr node, graph_ptr gp, int budget);
hotel_site_ptr HS_SATISFACTION(node_ptr node, graph_ptr gp);
hotel_site_ptr HS_DAY(hotel_site_ptr head, int period, int sitenum);