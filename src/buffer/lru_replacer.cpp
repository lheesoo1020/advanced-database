//===----------------------------------------------------------------------===//
//
//                         BusTub
//
// lru_replacer.cpp
//
// Identification: src/buffer/lru_replacer.cpp
//
// Copyright (c) 2015-2019, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include "buffer/lru_replacer.h"

namespace bustub {


LRUReplacer::LRUReplacer(size_t num_pages) {}

LRUReplacer::~LRUReplacer() = default;

bool LRUReplacer::Victim(frame_id_t *frame_id) {
	lru_mutex.lock();
	if (unpinned_frames.size() > 0) {
		*frame_id = unpinned_frames.back();
		unpinned_frames.pop_back();
		lru_mutex.unlock();
		return true;
	}
	lru_mutex.unlock();
	return false;
}

void LRUReplacer::Pin(frame_id_t frame_id) {
	lru_mutex.lock();
	if (!unpinned_frames.empty()) {
		std::list<frame_id_t>::iterator iter = unpinned_frames.begin();
		while (iter != unpinned_frames.end()) {
			if (*iter == frame_id) {
				iter = unpinned_frames.erase(iter);
			} else {
				iter++;
			}
		}
	}
	lru_mutex.unlock();
}

void LRUReplacer::Unpin(frame_id_t frame_id) {
	lru_mutex.lock();
	bool check = false;
	if (!unpinned_frames.empty()) {
		std::list<frame_id_t>::iterator iter = unpinned_frames.begin();
		while (iter != unpinned_frames.end()) {
			if (*iter == frame_id) {
				check = true;
			}
			iter++;
		}
	}
	if (!check) {
		unpinned_frames.push_front(frame_id);
	}
	lru_mutex.unlock();
}

size_t LRUReplacer::Size() {
	return unpinned_frames.size();
}

}  // namespace bustub
