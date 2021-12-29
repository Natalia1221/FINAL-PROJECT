


void MengubahData(){
	Barang data1;
	found =0;
	FILE *fh = fopen("Data_Barang.txt", "r");
	FILE *fp = fopen("temp.txt", "w");
	printf("Masukkan Kode Barang yang Diubah : ");
	scanf("%d", &cari);
	if(fh!=NULL){
		
		while(fread(&data1, sizeof(Barang),1, fh)){
			if(data1.kode == cari){
				found= 1;
				printf("========================================\n");
    			printf("           UBAH DATA BARANG\n");
    			printf("========================================\n");
				printf("Kode Barang  : ");
				scanf("%d", &data1.kode);
    			printf("Nama Barang  : "); fflush(stdin);
    			fgets(data1.nama ,50, stdin);
    			data1.nama[strlen(data1.nama)-1] = '\0';
    			printf("Harga Barang : ");
    			scanf("%d", &data1.harga);
    			printf("Jumlah Barang: ");
    			scanf("%d", &data1.stock);
				printf("========================================\n\n\n\n");
		}
		fwrite(&data1, sizeof(Barang),1, fp);
	}
	fclose(fh);
	fclose(fp);
		
		if(!found){
			printf("==============================\n");
			printf("     DATA TIDAK DITEMUKAN \n");
			printf("==============================\n\n\n\n");	
		}
		else if (found){
			fp = fopen("temp.txt", "r");
			fh = fopen("Data_Barang.txt", "w");
			
			while(fread(&data1, sizeof(Barang),1, fp)){
			fwrite(&data1, sizeof(Barang), 1, fh);
			}
			
			fclose(fh);
			fclose(fp);
		}
		
	}
	
	else if(fh==NULL){
		printf("==============================\n");
		printf("     DATA MASIH KOSONG \n");
		printf("==============================\n\n\n\n");
	}
	

	
}

void Menghapus(){
	Barang data1;
	found =0;
	FILE *fh = fopen("Data_Barang.txt", "r");
	FILE *fp = fopen("temp.txt", "w");
	printf("Masukkan Kode Barang yang Dihapus : ");
	scanf("%d", &cari);
	if(fh!=NULL){
		
		while(fread(&data1, sizeof(Barang),1, fh)){
			if(data1.kode == cari){
				found= 1;	
			}
			else 
			fwrite(&data1, sizeof(Barang),1, fp);
	}
	fclose(fh);
	fclose(fp);
		
		if(!found){
			printf("==============================\n");
			printf("     DATA TIDAK DITEMUKAN \n");
			printf("==============================\n\n\n\n");	
		}
		else if (found){
			fp = fopen("temp.txt", "r");
			fh = fopen("Data_Barang.txt", "w");
			
			while(fread(&data1, sizeof(Barang),1, fp)){
			fwrite(&data1, sizeof(Barang), 1, fh);
			}
			printf("==============================\n");
			printf("     DATA TELAH DIHAPUS \n");
			printf("==============================\n\n\n\n");	
			fclose(fh);
			fclose(fp);
		}
		
	}
	
	else if(fh==NULL){
		printf("==============================\n");
		printf("     DATA MASIH KOSONG \n");
		printf("==============================\n\n\n\n");
	}	
}
