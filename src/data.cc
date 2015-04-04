// use direct path for to save compile flags
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <dmlc/io.h>
#include <dmlc/logging.h>

#include "data/basic_row_iter.h"
#include "data/libsvm_parser.h"

namespace dmlc {
namespace data {
template<typename IndexType>
static IDataIter<RowBlock<IndexType> > *
CreateIter_(InputSplit *source,
            const std::string &cfg) {
  return new BasicRowIter<IndexType>(new LibSVMParser(source));
}
}  // namespace data
template<>
IDataIter<RowBlock<unsigned> > *
RowBlock<unsigned>::CreateIter(InputSplit *source,
                               const std::string &cfg) {
  return data::CreateIter_<unsigned>(source, cfg);
}
}  // dmlc
