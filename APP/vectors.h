#ifndef _VECTORS_H_
#define _VECTORS_H_

#ifdef __cplusplus
extern "C" {
#endif
void UndefinedException(void);
void FIQInterrupt(void);
void IRQInterrupt(void);
void SWInterrupt(void);
void DataAbortInterrupt(void);
void PrefetchAbortInterrupt(void);

#ifdef __cplusplus
}
#endif

#endif /* protection macro */
