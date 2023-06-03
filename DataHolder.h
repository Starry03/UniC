//
// Created by andre on 6/1/2023.
//

#ifndef STARRY_CLIBRARY_DATAHOLDER_H
#define STARRY_CLIBRARY_DATAHOLDER_H

#endif //STARRY_CLIBRARY_DATAHOLDER_H

typedef struct {
    void *info;
    int type;
} DataHolder_;

typedef DataHolder_ *DataHolder;
#define DATA_HOLDER_SIZE 8

typedef int DataType;
#define Data_int 0
#define Data_float 1
#define Data_double 2
#define Data_char 3
#define Data_string 4


DataHolder NewDataHolder(void *info, int type);

void DataHolder_Print(DataHolder dataHolder);
