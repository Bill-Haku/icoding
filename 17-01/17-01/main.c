#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <stdbool.h>

#include <ctype.h>


#define MAX 100

#define GOODS_FILE_NAME "goodsinfo.txt"


#define MAX_ID_LEN 30

#define MAX_NAME_LEN 30

#define MAX_PRICE_LEN 30

#define MAX_DISCOUNT_LEN 30


typedef struct {
    char    goods_id[MAX_ID_LEN];
    char    goods_name[MAX_NAME_LEN];
    int     goods_price;
    char    goods_discount[MAX_DISCOUNT_LEN];
    int     goods_amount;
    int     goods_remain;
} GoodsInfo;

typedef struct node
{
    GoodsInfo data;
    struct node *next;
} GoodsList;


//全局变量，存储当前商品的数量
int CurrentCnt;

GoodsInfo read_goods_info();
void init_list(GoodsList **pL);
void destory_list(GoodsList **pL);
void destory_list_and_file(GoodsList **pL);
int save_to_file(GoodsList *L);
void output_one_item(GoodsList *L);
void output_all_items(GoodsList *L);
bool insert_item(GoodsList *L, GoodsInfo item, int choice);
bool delete_item(GoodsList *L, char* goods_id);
GoodsList* search_item(GoodsList *L, char* goods_id);
bool change_item(GoodsList *L, char* goods_id, GoodsInfo new_info);
void bubble_sort(GoodsList *L);


int read_line(char str[], int n)
{
    int ch, i = 0;

    while (isspace(ch = getchar()))
        ;
    while (ch != '\n' && ch != EOF) {
        if (i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}

/**********************************************************
 * main
 **********************************************************/
int main(void)
{
    GoodsList *goodsList;
    init_list(&goodsList);
    GoodsInfo item;
    char temp_id[MAX_ID_LEN];
    while (1) {
    int choice;
    printf("超市商品管理系统\n");
    printf("********************************************\n");
    printf("1.显示所有商品的信息:\n");
    printf("2.修改某个商品的信息:\n");
    printf("3.插入某个商品的信息:\n");
    printf("4.删除某个商品的信息:\n");
    printf("5.查找某个商品的信息:\n");
    printf("6.商品存盘并退出系统:\n");
    printf("7.对商品价格进行排序:\n");
    printf("8.(慎用)删除所有内容:\n");
    printf("其他.不存盘并退出系统:\n");
    printf("********************************************\n");
    printf("输入您的选择: ");

    scanf("%d", &choice);
    switch (choice) {
      case 1:
         /* 补充代码*/
      case 2:
        item = read_goods_info();
        printf("输入要修改记录的 ID：");
         /* 补充代码read_line调用*/
         /* 补充代码change_item调用*/
        break;
        case 3:
        item = read_goods_info();
        int pos;
        printf("输入数字表明你要插入的商品位置：0.商品列表尾部 1.商品列表头部 i.商品列表中间第i号位置\n");
        scanf("%d", &pos);
         /* 补充代码insert_item调用*/
        break;
      case 4:
        printf("输入要删除记录的 ID：");
         /* 补充代码read_line调用*/
         /* 补充代码delete_item调用*/
        break;
      case 5:
        printf("输入要删除记录的 ID：");
         /* 补充代码read_line调用*/
         /* 补充代码search_item调用*/
        break;
      case 6:
         /* 补充代码save_to_file调用*/
        printf("您已经存盘并退出超市商品管理系统!\n");
        return 0;
      case 7:
         /* 补充代码bubble_sort调用*/
        break;
      case 8:
        /* 补充代码destory_list_and_file调用*/
        printf("您已经删除商品文件内容以及链表内容!\n");
        break;
      default:
        /* 补充代码destory_lis调用*/
        printf("您已经退出超市商品管理系统!\n");
        return 0;
    }
    }
}

/**********************************************************
 * init_list
 **********************************************************/
void init_list(GoodsList **L) {
    FILE *fp;
    GoodsInfo goodsInfo;
    GoodsList *p, *r;
    
    (*L) = (GoodsList *)malloc(sizeof(GoodsList));
    r = (*L);
    if ((fp = fopen(GOODS_FILE_NAME, "r")) == NULL)
    {
        if ((fp = fopen(GOODS_FILE_NAME, "w")) == NULL)
            printf("提示：不能创建商品文件\n");
    }
    else {
        while (!feof(fp))
        {
            fscanf(fp, "%s", goodsInfo.goods_id);
            /* 仿写fscanf完成goodsInfo其他部分的内容*/
            fscanf(fp, "\t%s", goodsInfo.goods_name);
            fscanf(fp, "\t%d", &goodsInfo.goods_price);
            fscanf(fp, "\t%s", goodsInfo.goods_discount);
            fscanf(fp, "\t%d", &goodsInfo.goods_amount);
            fscanf(fp, "\t%d\n", &goodsInfo.goods_remain);
            p = (GoodsList*)malloc(sizeof(GoodsList));
            /* 完成GoodsList的构建*/
            p->data=goodsInfo;
            
            r->next=p;
            r=p;
            CurrentCnt++;
        }
    }
    fclose(fp);
    r->next = NULL;
    printf("商品的链表文件已建立，有%d个商品记录\n", CurrentCnt);
}


/**********************************************************
 * insert_item
 **********************************************************/
bool insert_item(GoodsList *L, GoodsInfo goodsInfo, int choice) {
    GoodsList *temp;
    GoodsList *pre = L, *p = L->next;
    int i=1;
    if (CurrentCnt >= 100) {
        printf("信息库已满，要插入请先删除一定量的商品数据!\n");
        return false;
    }

    switch (choice) {
        case 0:
                //尾插法插入新商品
                /* 补充代码*/
            while(p!=NULL) {
                pre=p;
                p=p->next;
            }
            
            temp=(GoodsList*)malloc(sizeof(GoodsList));
            if(temp==NULL)
                return false;

            temp->data=goodsInfo;
            
            temp->next=p;
            pre->next=temp;
            
            CurrentCnt++;
            return true;
        case 1:
                //头插法插入新商品
                /* 补充代码*/
            temp=(GoodsList*)malloc(sizeof(GoodsList));
            
            temp->data=goodsInfo;
            
            temp->next=pre->next;
            pre->next=temp;
            
            CurrentCnt++;
            return true;
         default:
                //中间i号位置插入新商品，例如：输入3，应该在第二个节点后插入新节点
    // CurrentCnt 改为 CurrentCnt+1，因为当 CurrentCnt 为2时，链表中有两个记录，
    // 此时输入3，即 choise为 3，表示在第二条记录后插入数据，新记录成为第3条数据
    if (choice <= CurrentCnt+1 && choice > 0) {
             /* 补充代码*/
        while(i<choice) {
            pre=p;
            p=p->next;
            i++;
        }
        temp=(GoodsList*)malloc(sizeof(GoodsList));
        
        temp->data=goodsInfo;
        
        temp->next=pre->next;
        pre->next=temp;
        
        CurrentCnt++;
        return true;
    }
    else {
                printf("输入的位置超出当前商品列表范围\n");
                return false;
        }
    }
}



/**********************************************************
 * delete_item
 **********************************************************/
bool delete_item(GoodsList *L, char* goods_id) {
     GoodsList *pre = L, *p = L->next;
      /* 补充代码*/
    while(p->data.goods_id!=goods_id) {
        pre=pre->next;
        p=pre->next;
    }
    pre->next=p->next;
    free(p);
    
    return true;
}


/**********************************************************
 * search_item
 **********************************************************/
GoodsList* search_item(GoodsList *L, char* goods_id) {
    GoodsList *p = L->next;
    /* 补充代码*/
    
    return true;
}


/**********************************************************
 * change_item
 **********************************************************/
bool change_item(GoodsList *L, char* goods_id, GoodsInfo new_info) {
     GoodsList *p = L->next;
     GoodsList *ptarget = search_item(L, goods_id);
     /* 补充代码*/
    return true;
}


/**********************************************************
 *output_one_item
 **********************************************************/
void output_one_item(GoodsList *p){
    /* 补充代码*/
}

/**********************************************************
 * output_all_items
 **********************************************************/
void output_all_items(GoodsList *L)
{
    /* 补充代码*/
}


/**********************************************************
 * destory_list
 **********************************************************/
void destory_list(GoodsList **L) {
    if (L == NULL || *L == NULL)
        return;
    GoodsList *pre = *L, *p = (*L)->next;
    /* 补充代码*/
}

/**********************************************************
 * destory_list_and_file
 **********************************************************/

void destory_list_and_file(GoodsList **L) {
     /* 补充代码：调用destory_list*/
    remove(GOODS_FILE_NAME);
}
/**********************************************************
 * save_to_file
 **********************************************************/
int save_to_file(GoodsList *L) {
    if(L == NULL)
        return 0;
    GoodsList *p = L->next;
    FILE *fp;
    if ((fp = fopen("goodsinfo.txt", "w")) == NULL)
    {
        printf("提示：不能打开商品文件\n");
        return 0;
    }
    int save_count = 0;
    while (p != NULL)
    {
        fprintf(fp, "%s\t", p->data.goods_id);
       /* 仿写fprintf完成goodsInfo其他部分的内容*/
        p = p->next;
        save_count++;
    }
    fclose(fp);
    return save_count;
}


/**********************************************************
 * bubble_sort
 **********************************************************/
void bubble_sort(GoodsList *L) {
    GoodsList *p;
    GoodsInfo temp;
    int n = CurrentCnt;
    int i, j;
    
    if (L == NULL || L->next == NULL)
        printf("当前链表中没有商品\n");
    for (j = 1; j < n; ++j) {
        p = L->next;
        for (i = 0; i < n - j; ++i) {
            if (p->data.goods_price > p->next->data.goods_price) {
    /* 补充代码*/
            }
            p = p->next;
        }
    }
}


/**********************************************************
 * read_goods_info
 **********************************************************/
GoodsInfo read_goods_info(){
    GoodsInfo goodsInfo;
    printf("输入你要插入的商品信息：\n");
    printf("商品ID：");
     /* 补充代码read_line调用*/
    printf("商品名称：");
     /* 补充代码read_line调用*/
    printf("商品价格：");
    scanf("%d",&goodsInfo.goods_price);
    printf("商品折扣：");
     /* 补充代码read_line调用*/
    printf("商品数量：");
    scanf("%d", &goodsInfo.goods_amount);
    printf("商品剩余：");
    scanf("%d", &goodsInfo.goods_remain);
    return goodsInfo;
}

