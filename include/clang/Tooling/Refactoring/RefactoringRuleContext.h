//===--- RefactoringRuleContext.h - Clang refactoring library -------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLING_REFACTOR_REFACTORING_RULE_CONTEXT_H
#define LLVM_CLANG_TOOLING_REFACTOR_REFACTORING_RULE_CONTEXT_H

#include "clang/Basic/SourceManager.h"

namespace clang {
namespace tooling {

/// The refactoring rule context stores all of the inputs that might be needed
/// by a refactoring action rule. It can create the specialized
/// \c ASTRefactoringOperation or \c PreprocessorRefactoringOperation values
/// that can be used by the refactoring action rules.
///
/// The following inputs are stored by the operation:
///
///   - SourceManager: a reference to a valid source manager.
///
///   - SelectionRange: an optional source selection ranges that can be used
///     to represent a selection in an editor.
class RefactoringRuleContext {
public:
  RefactoringRuleContext(const SourceManager &SM) : SM(SM) {}

  const SourceManager &getSources() const { return SM; }

  /// Returns the current source selection range as set by the
  /// refactoring engine. Can be invalid.
  SourceRange getSelectionRange() const { return SelectionRange; }

  void setSelectionRange(SourceRange R) { SelectionRange = R; }

private:
  /// The source manager for the translation unit / file on which a refactoring
  /// action might operate on.
  const SourceManager &SM;
  /// An optional source selection range that's commonly used to represent
  /// a selection in an editor.
  SourceRange SelectionRange;
};

} // end namespace tooling
} // end namespace clang

#endif // LLVM_CLANG_TOOLING_REFACTOR_REFACTORING_RULE_CONTEXT_H
