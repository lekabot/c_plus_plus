/**
 * @file records.h
 * @brief This file contains the definition of the Records structure and related
 * functions.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_RECORDS_RECORDS_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_RECORDS_RECORDS_H_

#include <stdbool.h>

#define RECORDS_NUMBER (5)
#define TETRIS_RECORDS_FILE_NAME "tetris_records.records_"
#define SNAKE_RECORDS_FILE_NAME "snake_records.records_"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Structure representing a record including name, score, and current
 * player flag.
 */
typedef struct {
  bool isCurrentPlayer; /**< Flag to indicate if the record belongs to the
                           current player. */
  char name[20];        /**< Name associated with the record. */
  int score;            /**< Score associated with the record. */
} Record;

/**
 * @brief Structure representing a collection of records.
 */
typedef struct {
  Record records[RECORDS_NUMBER]; /**< Array of records. */
} Records;

/**
 * @brief Initialize the records with default values.
 *
 * @param records Pointer to the Records structure to be initialized.
 */
void initRecords(Records *records);

/**
 * @brief Add a new record to the records.
 *
 * @param records Pointer to the Records structure.
 * @param name The name for the new record.
 * @param score The score for the new record.
 * @param filename The name of the file to save the records to.
 */
void addRecord(Records *records, const char *name, int score,
               const char *filename);

/**
 * @brief Remove a specific record from the records.
 *
 * @param records Pointer to the Records structure.
 * @param name The name of the record to be removed.
 * @param filename The name of the file to save the records to.
 */
void removeRecord(Records *records, const char *name, const char *filename);

/**
 * @brief Save the records to a file.
 *
 * @param records Pointer to the Records structure to be saved.
 * @param filename The name of the file to save the records to.
 * @return true if the records are saved successfully, false otherwise.
 */
bool saveRecords(const Records *records, const char *filename);

/**
 * @brief Load the records from a file.
 *
 * @param records Pointer to the Records structure to be loaded.
 * @param filename The name of the file to load the records from.
 * @return true if the records are loaded successfully, false otherwise.
 */
bool loadRecords(Records *records, const char *filename);

/**
 * @brief Sort the records in descending order based on the score.
 *
 * @param records Pointer to the Records structure to be sorted.
 */
void sortRecords(Records *records);

#ifdef __cplusplus
}
#endif

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_RECORDS_RECORDS_H_
