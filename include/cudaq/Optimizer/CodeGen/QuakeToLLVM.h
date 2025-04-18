/****************************************************************-*- C++ -*-****
 * Copyright (c) 2022 - 2025 NVIDIA Corporation & Affiliates.                  *
 * All rights reserved.                                                        *
 *                                                                             *
 * This source code and the accompanying materials are made available under    *
 * the terms of the Apache License 2.0 which accompanies this distribution.    *
 ******************************************************************************/

#pragma once

namespace mlir {
class LLVMTypeConverter;
class RewritePatternSet;
} // namespace mlir

namespace cudaq::opt {

void populateQuakeToLLVMPatterns(mlir::LLVMTypeConverter &typeConverter,
                                 mlir::RewritePatternSet &patterns,
                                 unsigned &measureCounter);

} // namespace cudaq::opt
