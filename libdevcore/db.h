/*
    This file is part of cpp-aquachain.

    cpp-aquachain is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    cpp-aquachain is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with cpp-aquachain.  If not, see <http://www.gnu.org/licenses/>.
*/
/** @file DB.h
 * @author Gav Wood <i@gavwood.com>
 * @date 2014
 */

#pragma once

#include "Exceptions.h"
#include "dbfwd.h"

#include <memory>
#include <string>

namespace dev
{
namespace db
{
// WriteBatchFace implements database write batch for a specific concrete
// database implementation.
class WriteBatchFace
{
public:
    virtual ~WriteBatchFace() = default;

    virtual void insert(Slice _key, Slice _value) = 0;
    virtual void kill(Slice _key) = 0;

protected:
    WriteBatchFace() = default;
    // Noncopyable
    WriteBatchFace(WriteBatchFace const&) = delete;
    WriteBatchFace& operator=(WriteBatchFace const&) = delete;
    // Nonmovable
    WriteBatchFace(WriteBatchFace&&) = delete;
    WriteBatchFace& operator=(WriteBatchFace&&) = delete;
};

class DatabaseFace
{
public:
    virtual ~DatabaseFace() = default;
    virtual std::string lookup(Slice _key) const = 0;
    virtual bool exists(Slice _key) const = 0;
    virtual void insert(Slice _key, Slice _value) = 0;
    virtual void kill(Slice _key) = 0;

    virtual std::unique_ptr<WriteBatchFace> createWriteBatch() const = 0;
    virtual void commit(std::unique_ptr<WriteBatchFace> _batch) = 0;

    // A database must implement the `forEach` maquaod that allows the caller
    // to pass in a function `f`, which will be called with the key and value
    // of each record in the database. If `f` returns false, the `forEach`
    // maquaod must return immediately.
    virtual void forEach(std::function<bool(Slice, Slice)> f) const = 0;
};

struct FailedToOpenDB : virtual Exception
{
    using Exception::Exception;
};
struct FailedInsertInDB : virtual Exception
{
    using Exception::Exception;
};
struct FailedLookupInDB : virtual Exception
{
    using Exception::Exception;
};
struct FailedDeleteInDB : virtual Exception
{
    using Exception::Exception;
};
struct FailedCommitInDB : virtual Exception
{
    using Exception::Exception;
};
struct FailedRollbackInDB : virtual Exception
{
    using Exception::Exception;
};
struct FailedIterateDB : virtual Exception
{
    using Exception::Exception;
};

}  // namespace db
}  // namespace dev
