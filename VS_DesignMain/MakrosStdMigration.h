/*
 * MakrosStdMigration.h
 *
 *  Created on: 21.11.2014
 *      Author: Gerd
 */

#ifndef MAKROSSTDMIGRATION_H_
#define MAKROSSTDMIGRATION_H_

#if __cplusplus <= 199711L //  201103L
#define SmartPointer std::auto_ptr
#else
#define SmartPointer std::unique_ptr
#endif

#endif /* MAKROSSTDMIGRATION_H_ */
