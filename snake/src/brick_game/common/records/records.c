#include "records.h"

#include <stdio.h>
#include <string.h>

void initRecords(Records *records) {
  for (int i = 0; i < RECORDS_NUMBER; ++i) {
    records->records[i].isCurrentPlayer = false;
    records->records[i].score = 0;
    records->records[i].name[0] = '\0';
  }
}

void addRecord(Records *records, const char *name, int score,
               const char *filename) {
  if (strlen(name) == 0) {
    return;
  }
  bool flagHandled = false;
  for (int i = 0; i < RECORDS_NUMBER; ++i) {
    if (strcmp(records->records[i].name, name) == 0) {
      if (score > records->records[i].score) {
        records->records[i].score = score;
      }
      flagHandled = true;
    }
  }

  int position = RECORDS_NUMBER - 1;
  for (int i = RECORDS_NUMBER - 1; i >= 0 && !flagHandled; --i) {
    if (score > records->records[i].score) {
      position = i;
    } else {
      break;
    }
  }

  for (int i = RECORDS_NUMBER - 1; i > position && !flagHandled; --i) {
    records->records[i] = records->records[i - 1];
  }

  if (!flagHandled) {
    records->records[position].isCurrentPlayer = true;
    records->records[position].score = score;
    snprintf(records->records[position].name, 18, "%s", name);
  }
  sortRecords(records);
  saveRecords(records, filename);
  loadRecords(records, filename);
}

void removeRecord(Records *records, const char *name, const char *filename) {
  bool found = false;
  int i;

  for (i = 0; i < RECORDS_NUMBER; ++i) {
    if (strcmp(records->records[i].name, name) == 0) {
      found = true;
      break;
    }
  }

  if (found) {
    for (int j = i; j < RECORDS_NUMBER - 1; ++j) {
      records->records[j] = records->records[j + 1];
    }

    records->records[RECORDS_NUMBER - 1].isCurrentPlayer = false;
    records->records[RECORDS_NUMBER - 1].score = 0;
    records->records[RECORDS_NUMBER - 1].name[0] = '\0';
  }
  sortRecords(records);
  saveRecords(records, filename);
  loadRecords(records, filename);
}

bool saveRecords(const Records *records, const char *filename) {
  FILE *file = fopen(filename, "wb");
  if (!file) {
    return false;
  }

  size_t numWritten = fwrite(records, sizeof(Records), 1, file);
  fclose(file);

  return numWritten == 1;
}

bool loadRecords(Records *records, const char *filename) {
  FILE *file = fopen(filename, "rb");
  if (!file) {
    return false;
  }

  size_t numRead = fread(records, sizeof(Records), 1, file);
  fclose(file);

  return numRead == 1;
}

void sortRecords(Records *records) {
  bool swapped = false;

  do {
    swapped = false;
    for (int i = 0; i < RECORDS_NUMBER - 1; ++i) {
      if (records->records[i].score < records->records[i + 1].score) {
        Record temp_record = records->records[i];
        records->records[i] = records->records[i + 1];
        records->records[i + 1] = temp_record;
        swapped = true;
      }
    }
  } while (swapped);
}